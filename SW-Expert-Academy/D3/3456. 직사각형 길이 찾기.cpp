#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		int a, b, c; cin >> a >> b >> c;
		cout << "#" << tt << " ";
		if (c == a) cout << b;
		else if (c == b) cout << a;
		else cout << c;
		cout << "\n";
	}
	return 0;
}