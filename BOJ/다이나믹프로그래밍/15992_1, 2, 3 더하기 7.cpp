#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000009
using namespace std;
typedef long long ll;
ll t, n, m;
ll dp[1001][1001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	dp[1][1] = dp[2][1] = dp[2][2] = dp[3][1] = dp[3][3] = 1;
	dp[3][2] = 2;

	for (int i = 4; i <= 1000; i++) {
		for (int k = 1; k <= 3; k++) {
			for (int j = 2; j <= 1000; j++) {
				dp[i][j] += dp[i - k][j - 1]%MOD;
				dp[i][j] % MOD;
			}
		}
	}
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << dp[n][m] % MOD << "\n";
	}
	return 0;
}