#include <iostream>
using namespace std;
int main() {
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		int p, q, r, s, w; cin >> p >> q >> r >> s >> w;
		int cost = 0;
		cost = w * p;
		if (w <= r) {
			if (cost > q) cost = q;
		}
		else {
			if (cost > (q + s * (w - r)))cost = q + s*(w - r);
		}
		cout << "#" << tt << " " << cost << "\n";
	}
	return 0;
}