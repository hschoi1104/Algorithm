#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
vector<int>v;
int chk[21];
int ans = 200001;
void init() {
	v.clear();
	ans = 200001;
	memset(chk, 0, sizeof(chk));
}
void go(int j, int sum, int b) {
	if (sum >= b) { ans = min(ans, sum - b); return; }

	for (int i = j; i < v.size(); i++) {
		if (chk[i]) continue;
		chk[i] = 1;
		go(i, sum + v[i], b);
		chk[i] = 0;
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		init();
		int n, b; cin >> n >> b;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		go(0, 0, b);
		cout << "#" << tt << " " << ans << "\n";
	}
	return 0;
}