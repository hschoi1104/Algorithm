#include <stdio.h>
int arr[16][16];
int brr[16][16];
int ans;
void goX(int i, int j, int k, int n) {
	int cnt = 0;
	for (int k = j; k < n && arr[i][k] != 0; k++) {
		cnt++;
		arr[i][k] = 0;
	}
	if (cnt == k) ans += 1;
	return;
}
void goY(int i, int j, int k, int n) {
	int cnt = 0;
	for (int k = i; k < n && brr[k][j] != 0; k++) {
		cnt += 1;
		brr[k][j] = 0;
	}
	if (cnt == k) ans += 1;
	return;
}
int main() {
	int t; scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		ans = 0;
		int n, k; scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
				brr[i][j] = arr[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 1) goX(i, j, k, n);
				if (brr[i][j] == 1) goY(i, j, k, n);
			}
		}

		printf("#%d %d\n", tt, ans);
	}
	return 0;
}