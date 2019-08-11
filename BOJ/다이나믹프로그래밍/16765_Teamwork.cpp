#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int arr[10002];
int dp[10002];
int n, k;
int ans = 0;
int go(int index, int k) {
	int maxval = 0, ans = 0;
	int &ret = dp[index];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < k && i+index < n; i++) {
		maxval = max(maxval, arr[i + index]);
		ans = max(ans, maxval*(i + 1) + go(index + i + 1, k));
	}
	return dp[index] = ans;
}
int main() {
	scanf("%d %d", &n, &k);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	printf("%d", go(0, k));
	return 0;
}