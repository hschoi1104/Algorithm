#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>v, w;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x, n, ans = 0; cin >> n;
	for (int i = 0; i < n; i++) cin >> x, v.push_back(x), w.push_back(x);
	sort(w.begin(), w.end());
	bool chk = false;
	for (int i = 0; i < v.size(); i++) if (v[i] != w[i]) ans += 1, chk = true;
	if (chk) ans -= 1;
	cout << ans;
	return 0;
}