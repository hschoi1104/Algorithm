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
		bool flag = false;
		for (int i = 0; i < n; i++) {
			int x; cin >> x; v.push_back(x);
		}
		for (int i = 0; i < v.size() - 2; i++) {
			if (flag) break;
			for (int j = i + 2; j < v.size(); j++) {
				if (v[i] == v[j]) {
					flag = true;
					break;
				}
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
		v.clear();
	}
	return 0;
}