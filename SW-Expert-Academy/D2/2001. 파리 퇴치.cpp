#include <stdio.h>
int arr[16][16];
int main() {
	int t; scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		int n, m; scanf("%d %d", &n, &m);
		//input
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		int ans = 0;
		//bruteforce
		for (int i = 0; i < n - m + 1; i++) {
			for (int j = 0; j < n - m + 1; j++) {
				int tmp = 0;
				for (int k = i; k < i + m; k++) {
					for (int p = j; p < j + m; p++) {
						tmp += arr[k][p];
					}
				}
				if (ans < tmp) ans = tmp;
			}
		}
		printf("#%d %d\n", tt, ans);
	}
	return 0;
}