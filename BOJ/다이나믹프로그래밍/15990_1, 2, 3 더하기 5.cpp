#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000009
using namespace std;
typedef long long ll;
ll t, n;
ll dp[1000001][3];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	dp[1][0] = dp[2][1] = dp[3][0] = dp[3][1] = dp[3][2] = 1;
	for (int i = 4; i <= 100000; i++) {
		for (int k = 1; k <= 3; k++) {
			dp[i][k - 1] = (dp[i - k][0] + dp[i - k][1] + dp[i - k][2] - dp[i - k][k - 1]) % MOD;
		}
	}
	cin >> t;
	while (t--) {
		cin >> n;
		ll sum = 0;
		for (int i = 0; i < 3; i++)
			sum += dp[n][i] % MOD;
		cout << sum % MOD << "\n";
	}
	return 0;
}