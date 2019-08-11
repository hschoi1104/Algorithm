#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
int arr[1001];
int dp[1001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	memset(dp, -1, sizeof(dp));
	dp[0] = dp[1] = 0;
	for (int i = 2; i<=n; i++) {
		dp[i] = dp[i-1];
		int maxval = 0, minval = 100000000;
		maxval = max(arr[i], arr[i - 1]);
		minval = min(arr[i], arr[i - 1]);
		for (int j = i-2; j >= 1; j--) {
			maxval = max(maxval, arr[j+1]);
			minval = min(minval, arr[j+1]);
			dp[i] = max(dp[i], dp[j] + maxval-minval);
		}
		dp[i] = max(dp[i], maxval - minval);
	}
	printf("%d", dp[n]);
	return 0;
}