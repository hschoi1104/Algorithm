#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int dp[10001];
int coin[101];
int main() {
	int n,k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - coin[i] >= 0) dp[j] += dp[j - coin[i]];
		}
	}
	printf("%d", dp[k]);
	return 0;
}
