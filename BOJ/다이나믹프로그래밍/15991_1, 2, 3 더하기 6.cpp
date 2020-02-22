#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000009
using namespace std;
typedef long long ll;
ll t, n;
ll dp[1000001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	dp[1] = 1;
	dp[2] = dp[3] = 2;

	for (int i = 4; i <= 100000; i++) {
		for (int k = 1; k <= 3; k++) {
			if (i - k * 2 > 0)dp[i] += dp[i - k * 2];
			if (i - k * 2 == 0) dp[i] += 1;
		}
		dp[i] %= MOD;
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] % MOD << "\n";
	}
	return 0;
}