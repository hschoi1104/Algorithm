#include <iostream>
using namespace std;
int card[2];
int pos = 0;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	cin >> card[0] >> card[1];
	for (int i = 0; i < m; i++) {
		int t; cin >> t;
		if (pos == 1) {
			if (card[1] <= t) {
				pos = 0;
			}
		}
		else {
			if (card[0] <= t) {
				pos = 1;
			}
		}
	}
	if (pos) cout << card[1];
	else cout << card[0];
	return 0;
}