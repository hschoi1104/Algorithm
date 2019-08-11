#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int c[301];
int dp[301][3];
int n, x;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	dp[1][1] = c[1]; dp[2][1] = c[2]; dp[2][2] = c[1] + c[2];
	for (int i = 3; i <= n; i++) {
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + c[i];
		dp[i][2] = dp[i - 1][1] + c[i];
	}
	printf("%d", max(dp[n][1], dp[n][2]));
	return 0;
}