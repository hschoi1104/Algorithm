#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int>v;
		int even = 0;
		int odd = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x; v.push_back(x);
			if (x % 2 == 0) even += 1;
			else odd += 1;
		}
		if (even == 0 && odd < 2) cout << -1;
		else if (even >= 1) {
			cout << 1 << "\n";
			int cnt = 0;
			for (int i = 0; i < v.size(); i++) {
				if (v[i] % 2 == 0) {
					cout << i + 1;
					cnt++;
					if (cnt) break;
				}
			}
		}
		else if (odd >= 2) {
			cout << 2 << "\n";
			int cnt = 0;
			for (int i = 0; i < v.size(); i++) {
				if (v[i] % 2 == 1) {
					cout << i + 1 << " ";
					cnt++;
					if (cnt==2) break;
				}
			}
		}
		cout << "\n";
	}
	return 0;
}