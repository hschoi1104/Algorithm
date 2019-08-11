#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int arr[110];
int dp[110][1010];
int main() {
	int n, m, s;
	scanf("%d %d %d", &n, &s, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		fill(dp[i], dp[i] + m + 1, -1);
	}
	dp[0][s] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i][j] == 1) {
				if (j - arr[i] >= 0) dp[i + 1][j - arr[i]] = 1;
				if (j + arr[i] <= m) dp[i + 1][j + arr[i]] = 1;
			}
		}
	}
	int ans = -1;
	for (int i = 0; i <=m; i++) {
		if (dp[n][i] == 1) ans = max(ans, i);
	}
	printf("%d", ans);
	return 0;
}