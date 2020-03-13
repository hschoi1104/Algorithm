#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		bool flag = true;
		int mh = INT_MAX;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			v.push_back(x);
			mh = min(mh, x);
		}
		for (int i = 0; i < n; i++) {
			v[i] = v[i] - mh;
			if (v[i] % 2 == 1) flag = false;
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
		v.clear();
	}
	return 0;
}