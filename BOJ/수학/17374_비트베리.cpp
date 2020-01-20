#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int p, q, a, b, c, d; cin >> p >> q >> a >> b >> c >> d;
		int coin = 0, ans=0;
		if (q >= c) coin += d * (q / c);
		int res = (p - coin) / (a + b);
		int tmp = res;
		ans = min(p - a * tmp, coin + b * tmp);
		tmp = res - 1;
		ans = max(ans,min(p - a * tmp, coin + b * tmp));
		tmp = res + 1;
		ans = max(ans,min(p - a * tmp, coin + b * tmp));
		cout << ans << "\n";
	}
	return 0;
}