#include <iostream>
#define MOD 1000000000
using namespace std;
typedef long long ll;
ll dp[11][101];
ll go(int p, int q) {
	if (q == 0 || p == 10 || p == -1) return 0;

	ll& ret = dp[p][q];
	if (ret != -1) return ret;
	ret = 0;
	return ret = (go(p - 1, q - 1) % MOD + go(p + 1, q - 1) % MOD) % MOD;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i <= 9; i++) fill(begin(dp[i]), end(dp[i]), -1);
	dp[0][0] = 0;
	for (int i = 0; i <= 9; i++) dp[i][1] = 1;
	ll ans = 0;
	for (int i = 1; i <= 9; i++) {
		ans += go(i, n);
		ans %= MOD;
	}
	cout << ans;
	return 0;
}