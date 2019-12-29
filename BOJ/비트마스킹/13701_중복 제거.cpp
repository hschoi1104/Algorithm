#include <stdio.h>
char arr[4194305];
int idx, n;
int main() {
	while (scanf("%d", &n) != -1) {
		idx = n / 8;
		if (arr[idx] & (1 << (n % 8))) continue;
		else {
			arr[idx] |= (1 << (n % 8));
			printf("%d ", n);
		}
	}
	return 0;
}