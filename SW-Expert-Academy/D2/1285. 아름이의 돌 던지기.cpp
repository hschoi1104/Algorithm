#include <iostream>
using namespace std;
int chk[1000001];
void init() {
	for (int i = 0; i <= 100000; i++)chk[i] = 0;
}
int main() {
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		init();
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if (x < 0) chk[-x] += 1;
			else chk[x] += 1;
		}
		for (int i = 0; i <= 100000; i++) {
			if (chk[i] != 0) {
				cout << "#" << tt << " " << i << " " << chk[i] << "\n";
				break;
			}
		}
	}
	return 0;
}