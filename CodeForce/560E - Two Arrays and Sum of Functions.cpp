#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
ll MOD = 998244353;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<ll>a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (ll i = 0; i < n; i++) {
		a[i] = a[i] * (i + 1) * (n - i);
	}
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		ans += (a[i] % MOD) * (b[i] % MOD);
		ans %= MOD;
	}
	cout << ans;
	return 0;
}