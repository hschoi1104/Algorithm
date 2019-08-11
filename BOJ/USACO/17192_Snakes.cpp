#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll dp[401][401];
ll sub[401];
ll rsub[401];
ll arr[401];
int main() {
	ll sum = 0, n, k; cin >> n >> k;
	for (ll i = 1; i <= n; i++) cin >> arr[i];
	sub[1] = dp[1][0] = sum = arr[1];
	for (ll i = 2; i <= n; i++) {
		sub[i] = max(sub[i - 1], arr[i]);
		dp[i][0] = sub[i] * (i);
		sum += arr[i];
	}
	//±×¹° º¯°æ È½¼ö
	for (ll j = 1; j <= k; j++) {
		//¹ì°³¼ö
		for (ll i = 1; i <= n; i++) {
			dp[i][j] = dp[i][j-1];
			ll max_val = arr[i];
			for (ll p = i; p >= 0; p--) {
				dp[i][j] = min(dp[i][j], dp[p][j - 1] + max_val * (i - p));
				max_val = max(max_val, arr[p]);
			}
		}
	}
	cout << dp[n][k] - sum;
	return 0;
}