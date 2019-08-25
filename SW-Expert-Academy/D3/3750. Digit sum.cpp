#include <iostream>
using namespace  std;
typedef long long ll;
ll go(ll n) {
	if (n < 10) return n;
	ll temp = 0;
	while (n >= 10) {
		temp += n % 10;
		n /= 10;
	}
	temp += n;
	return go(temp);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t; cin >> t;
	for (ll tt = 1; tt <= t; tt++) {
		ll n; cin >> n;
		cout << "#" << tt << " " << go(n) << "\n";
	}
	return 0;
}