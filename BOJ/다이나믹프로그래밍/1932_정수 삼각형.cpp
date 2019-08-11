#include <stdio.h>
#include <algorithm>
using namespace std;
int dp[501][501];
int arr[501][501];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	for (int j = 0; j <= i; j++)scanf("%d", &arr[i][j]);
	dp[0][0] = arr[0][0];
	for (int i = 0; i < n - 1; i++)	for (int j = 0; j <= i; j++) {
		dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + arr[i + 1][j]);
		dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + arr[i + 1][j + 1]);
	}
	int ans = 0;
	for (int j = 0; j < n; j++) ans = max(ans, dp[n - 1][j]);
	printf("%d", ans);
	return 0;
}