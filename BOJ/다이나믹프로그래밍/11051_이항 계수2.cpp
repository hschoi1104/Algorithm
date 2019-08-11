#include <stdio.h>
#include <string.h>
using namespace std;
int dp[1001][1001];
int go(int n, int k) {
	if (n == k) return 1;
	if (k == 1) return n;
	if (k == 0) return 1;
	int &ret = dp[n][k];
	if (ret != -1) return ret;
	ret = 0;
	return ret = go(n - 1, k) % 10007 + go(n - 1, k - 1) % 10007;
}
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	if (n / 2 > k)k = n - k;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (j == 0 || i == 0) dp[i][j] = 0;
			else if (i == 1 || j == 1)dp[i][j] = 1;
			else dp[i][j] = -1;
		}
	}
	printf("%d", go(n, k) % 10007);
	return 0;
}