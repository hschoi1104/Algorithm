#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000009
using namespace std;
typedef long long ll;
ll t, n, m;
ll dp[100001][2];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	dp[1][0] = dp[2][0] = dp[2][1] = 1;
	dp[3][0] = dp[3][1] = 2;

	for (int i = 4; i <= 100000; i++) {
		for (int k = 1; k <= 3; k++) {
			dp[i][0] += dp[i - k][1] % MOD;
			dp[i][1] += dp[i - k][0] % MOD;
		}
		dp[i][0] %= MOD, dp[i][1] %= MOD;
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n][0] % MOD << " " << dp[n][1] % MOD << "\n";
	}
	return 0;
}