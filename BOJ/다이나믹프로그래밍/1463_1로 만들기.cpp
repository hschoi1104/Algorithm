#include <stdio.h>
#include <algorithm>
using namespace std;
int dp[1000001],INF=999999999;
int main() {
	int n;
	scanf("%d", &n);
	fill(dp, dp + 1000000, INF);
	dp[n] = 0;
	for (int i = n; i > 0; i--) {
		if (dp[i] == INF) continue;
		if (i % 3 == 0) dp[i / 3] = min(dp[i/3],dp[i] + 1);
		if (i % 2 == 0) dp[i / 2] = min(dp[i/2],dp[i] + 1);
		dp[i - 1] = min(dp[i - 1], dp[i] + 1);
	}
	printf("%d", dp[1]);
	return 0;
}