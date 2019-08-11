#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[1001][1001];
int dp[1001][1001];
int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0) arr[i][j] = 1;
			else scanf("%1d", &arr[i][j]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j]) dp[i][j] = max(dp[i][j], min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]))) + 1;
			ans = max(ans, dp[i][j]);
		}
	}
	printf("%d", ans * ans);
	return 0;
}