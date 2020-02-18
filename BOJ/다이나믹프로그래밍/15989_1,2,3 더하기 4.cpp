#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
ll dp[10001][3];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	dp[1][0] = dp[2][0] = dp[2][1] = dp[3][0] = dp[3][1] = dp[3][2] = 1;
	for (int i = 4; i <= 10000; i++) {
		dp[i][0] = dp[i - 1][0];
		dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
		dp[i][2] = dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2];
	}
	while (t--) {
		ll n; cin >> n;
		cout << dp[n][0] + dp[n][1] + dp[n][2] << "\n";
	}
	return 0;
}