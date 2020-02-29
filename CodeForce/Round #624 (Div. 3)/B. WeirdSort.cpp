#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int chk[101];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		memset(chk, 0, sizeof(chk));
		int n, m; cin >> n >> m;
		vector<int>v, a, p;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			v.push_back(x);
			a.push_back(x);
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < m; i++) {
			int x; cin >> x; chk[x - 1] = 1;
		}
		sort(p.begin(), p.end());
		bool flag = true;
		for (int i = 0; i < v.size(); i++) {
			if (!flag) break;
			for (int j = 0; j < v.size() - i - 1; j++) {
				if (!flag) break;
				if (v[j] > v[j + 1]) {
					if (chk[j] == 0) {
						flag = false;
						break;
					}
					int temp = v[j];
					v[j] = v[j + 1];
					v[j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < v.size();i++) {
			if (v[i] != a[i]) {
				flag = false;
				break;
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}