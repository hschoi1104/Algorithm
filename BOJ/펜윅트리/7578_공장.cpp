#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>ft, a, b;
int pos[1000001];
void update(int i, int val) {
	while (i < ft.size()) {
		ft[i] += val;
		i += (i & -i);
	}
}
int sum(int i) {
	int res = 0;
	while (i > 0) {
		res += ft[i];
		i -= (i & -i);
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	ft.resize(n + 1); a.resize(n + 1); b.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		pos[b[i]] = i;
	}
	int ans = 0;
	for (int i = 1; i < a.size(); i++) {
		ans += (sum(n) - sum(pos[a[i]]));
		update(pos[a[i]], 1);
	}
	cout << ans;
	return 0;
}