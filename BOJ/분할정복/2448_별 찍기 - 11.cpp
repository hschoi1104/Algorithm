#include <stdio.h>
using namespace std;
int arr[3073][6145];
void go(int n, int y, int x) {
	if (n == 3) {
		arr[y][x] = 1;
		arr[y + 1][x - 1] = arr[y + 1][x + 1] = 1;
		for (int i = 0; i < 5; i++) arr[y + 2][x - 2 + i] =1;
		return;
	}
	go(n / 2, y, x);
	go(n / 2, y + n / 2 , x - n / 2);
	go(n / 2, y + n / 2 , x + n/2);
	return;
}
int main() {
	int n;
	scanf("%d", &n);
	go(n, 1, n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 2*n; j++) {
			if (arr[i][j] == 1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}