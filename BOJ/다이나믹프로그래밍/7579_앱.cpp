/*
*	DP[i][j] i번째 앱까지 사용했을때 비용 j로 얻는 최대 메모리용량
*	i번째 앱을 끄는 경우 dp[i][j+cost[i]] = max(dp[i][j+cost[i]],dp[i-1][j]+mem[i]) 
*	i번째 앱을 끄지 않는 경우 dp[i][j] = max(dp[i][j],dp[i-1][j])
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
ll dp[101][10001];
ll mem[101];
ll cost[101];

int main() {
	ll n, m;
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &mem[i]);
	for (int i = 1; i <= n; i++) scanf("%lld", &cost[i]);
	for (int i = 0; i <= 100; i++) fill(dp[i], dp[i] + 10000, -1);
	dp[0][0] = dp[1][0] = 0;
	dp[1][cost[1]] = mem[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10001; j++) {
			if (dp[i - 1][j] == -1)continue;
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (j + cost[i] > 10000)continue;
			dp[i][j + cost[i]] = max(dp[i][j + cost[i]], dp[i - 1][j] + mem[i]);
		}
	}
	for (int i = 0; i < 10001; i++) {
		if (dp[n][i] >= m) {
			printf("%d", i);
			break;
		}
	}
	return 0;
}
