#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		int n, m; cin >> n >> m;
		int a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			int tmp = 0;
			for (int j = 0; j < m; j++) {
				int x; cin >> x;
				if (x) tmp += 1;
			}
			if (tmp > b) { b = tmp, a = 1; }
			else if (tmp == b) a += 1;
		}
		cout << "#" << tt << " " << a << " " << b<<"\n";
	}
	return 0;
}