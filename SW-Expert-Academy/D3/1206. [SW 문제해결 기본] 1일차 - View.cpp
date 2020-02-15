#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int t = 1; t <= 10; t++) {
		vector<int> v;
		int n, ans = 0; cin >> n;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;  v.push_back(x);
		}

		for (int i = 2; i < n - 2; i++) {
			int rt = 0, lt = 0;
			lt = max(v[i - 1], v[i - 2]);
			rt = max(v[i + 1], v[i + 2]);
			if (v[i] > lt&& v[i] > rt) ans += v[i] - max(rt, lt);
		}
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}