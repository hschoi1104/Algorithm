#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll>a, b;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n; cin >> n;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ll x; cin >> x; a.push_back(x);
	}
	for (ll i = 0; i < n; i++) {
		ll x; cin >> x; a[i] -= x;
	}

	sort(a.begin(), a.end());

	for (ll i = 0; i < n; i++) {
		if (a[i] > 0) {
			ans += (n - i) * (n - i - 1) / 2;
			break;
		}
		else ans += (a.end() - upper_bound(a.begin() + i, a.end(), -a[i]));
	}
	cout << ans;
	return 0;
}