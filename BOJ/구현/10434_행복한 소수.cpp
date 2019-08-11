#include <stdio.h>
#include <string.h>
int arr[10002];
int chk[10002];
int sosu(int num) {
	if (arr[num] == 0) return 1;
	else return 0;
}
int happy(int num) {
	chk[num] = 1;
	while (1) {
		int sum = 0;
		while (1) {
			if (num < 10) {
				sum += (num % 10)*(num % 10);
				break;
			}
			sum += (num % 10)*(num % 10);
			num /= 10;
		}
		num = sum;
		if (chk[sum] == 0 && sum == 1) return 1;
		else if (chk[sum] == 1) return -1;
		chk[sum] = 1;
	}
}
int main() {
	for (int i = 2; i <= 10000; i++) {
		if (arr[i] == 1)continue;
		for (int j = i + i; j <= 10000; j += i) arr[j] = 1;
	}
	arr[1] = 1;
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		memset(chk, 0, sizeof(chk));
		scanf("%d %d", &a, &b);
		if (sosu(b) == 1 && happy(b) == 1) {
			printf("%d %d YES\n", a, b);
		}
		else printf("%d %d NO\n", a, b);
	}
	return 0;
}