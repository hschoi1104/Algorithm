#include <stdio.h>
#include <string.h>
typedef long long ll;
ll dp[50];
ll go(int n) {
	ll &ret = dp[n];
	if (ret != -1) return ret;
	ret = 0;
	return ret = go(n - 1) + go(n - 2);
}
int main() {
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	dp[1] = dp[2] = 1;
	int n;
	scanf("%d", &n);
	printf("%lld", go(n));
	return 0;
}