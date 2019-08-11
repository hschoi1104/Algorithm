#include <stdio.h>
#include <string.h>
int dp[13];
int n;
int go(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	int &ret = dp[n];
	if (ret != -1) return ret;
	ret = 0;
	return ret = go(n - 1) + go(n - 2) + go(n - 3);
}
int main() {
	int t;
	scanf("%d", &t);
	memset(dp, -1, sizeof(dp));
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	go(11);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
	return 0;
}