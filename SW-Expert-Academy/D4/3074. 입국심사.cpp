#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		vector<ll> v;
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++) {
			ll x; cin >> x;
			v.push_back(x);
		}
		ll left = 0, right = 1e18,ans =1e18;
		while (left <= right) {
			ll mid = (left + right) / 2;
			ll res = 0;
			for (auto i : v) {
				res += mid / i;
			}
			if (res >= m) {
				right = mid - 1;
				ans = min(ans, mid);
			}
			else left = mid + 1;
		}
		cout << "#" << tt << " " << ans << "\n";
	}
	return 0;
}