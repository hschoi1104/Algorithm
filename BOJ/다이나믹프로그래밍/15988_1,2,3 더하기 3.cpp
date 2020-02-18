#include <iostream>
#include <string.h>
#define MOD 1000000009
using namespace std;
typedef long long ll;
ll dp[1000001];
ll go(ll n) {
	if (dp[n] != -1) return dp[n] % MOD;
	for (int i = 4; i <= n; i++) {
		ll sum = 0;
		for (int j = 1; j <= 3; j++) {
			sum += dp[i - j] % MOD;
			sum %= MOD;
		}
		dp[i] = sum;
	}
	return dp[n] % MOD;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	memset(dp, -1, sizeof(dp));
	dp[1] = 1, dp[2] = 2, dp[3] = 4;
	while (t--) {
		ll n; cin >> n;
		go(n);
		cout << dp[n] << "\n";
	}
	return 0;
}