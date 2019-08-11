#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
using namespace std;
vector<set<string>>v;
int main() {
	int n; cin >> n;
	v.resize(n + 1);
	for (int i = 0; i < n; i++) {
		string s; int k;
		cin >> s >> k;
		for (int j = 0; j < k; j++) {
			cin >> s;
			v[i].insert(s);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			int res = 0;
			for (auto it : v[i]) {
				if (v[j].find(it) != v[j].end()) res += 1;
			}
			ans = max(ans, res);
		}
	}
	cout << ans+1 << "\n";
	return 0;
}