#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b; cin >> a >> b;
		if (a < b) {
			if ((b - a) % 2 == 1) {
				cout << 1 << "\n";
			}
			else if ((b - a) % 2 == 0) {
				cout << 2 << "\n";
			}
		}
		else if (a > b) {
			if ((a - b) % 2 == 1) {
				cout << 2 << "\n";
			}
			else if ((a - b) % 2 == 0) {
				cout << 1 << "\n";
			}
		}
		else if (a == b) cout << 0 << "\n";
	}
	return 0;
}