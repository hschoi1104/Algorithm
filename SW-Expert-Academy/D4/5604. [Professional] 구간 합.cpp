#include <iostream>
using namespace std;
typedef long long ll;
ll cnt(ll num) {
	ll sum = 0;
	while (num > 0) {
		sum += (num % 10);
		num /= 10;
	}
	return sum;
}
ll go(ll num) {
	ll pos = 1, ans = 0;
	while (num > 0) {
		ll tmp = 0;
		while (num % 10 != 9) {
			if (num == 0) break;
			tmp += cnt(num);
			num--;
		}
		if (num % 10 == 9) ans += ((num / 10) + 1) * 45 * pos;
		ans += tmp * pos;
		pos *= 10;
		num /= 10;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll tt; cin >> tt;
	for (int t = 1; t <= tt; t++) {
		ll a, b; cin >> a >> b;
		cout << "#" << t << " " << go(b) - go(a - 1) << "\n";
	}
	return 0;
}