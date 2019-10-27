#include <iostream>
#include <algorithm>
using namespace std;
int go(int n) {
	int res = 0;
	while (n > 0) {
		res += n % 10;
		n /= 10;
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m; cin >> m;
	for (int t = 1; t <= m; t++) {
		int mav = 0, miv = 100;
		for (int i = 0; i < 10; i++) {
			int x; cin >> x;
			int t = go(x);
			mav = max(mav, t); miv = min(miv, t);
		}
		cout << "#" << t << " " << mav << " " << miv<<"\n";
	}
	return 0;
}