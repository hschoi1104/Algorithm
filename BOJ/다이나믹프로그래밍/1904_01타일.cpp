#include <stdio.h>
#include <string.h>
int dp[1000001];
int n;
int go(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	int &ret = dp[n];
	if (ret != -1) return ret;
	ret = 0;
	return ret = (go(n - 2) % 15746 + go(n - 1) % 15746) % 15746;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	printf("%d", go(n) % 15746);
	return 0;
}