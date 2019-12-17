#include <stdio.h>
int arr[8][8];
int res[8][8][3];
void rotate(int n, int k) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res[j][n - i - 1][k] = arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = res[i][j][k];
		}
	}
}
void print(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
int main() {
	int t; scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		rotate(n, 0);
		rotate(n, 1);
		rotate(n, 2);
		printf("#%d\n", tt);
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < 3; k++) {
				for (int j = 0; j < n; j++) {
					printf("%d", res[i][j][k]);
				}
				printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}