#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll>v;
ll maxval = 0, sum = 0, ans = LLONG_MAX;
int main() {
	ll s, c; cin >> s >> c;
	for (int i = 0; i < s; i++) {
		ll x; cin >> x; v.push_back(x);
		maxval = max(maxval, x);
		sum += x;
	}
	ll l = 0, r = LLONG_MAX;
	while (l <= r) {
		ll mid = (l + r) / 2;
		ll cnt = 0;
		if (maxval < mid) {
			r = mid - 1;
			continue;
		}
		for (auto it : v) {
			cnt += it / mid;
		}
		if (cnt >= c) ans = min(ans, sum - c * mid);
		if (cnt < c) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ans;
	return 0;
}