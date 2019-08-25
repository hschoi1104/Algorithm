#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		int sum = 0;
		for (int i = 0; i < 5; i++) {
			int n; cin >> n;
			if (n < 40)sum += 40;
			else sum += n;
		}
		cout << "#" << tt << " " << sum / 5<<"\n";
	}
	return 0;
}