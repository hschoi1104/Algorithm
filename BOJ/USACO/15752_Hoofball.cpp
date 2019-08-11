#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>cow;
int pass[101];
int x, n, ans = 0;
int go(int idx) {
	if (idx == 0) return idx + 1;
	if (idx == n - 1) return idx - 1;

	if (cow[idx] - cow[idx - 1] <= cow[idx + 1] - cow[idx]) return idx - 1;
	else return idx + 1;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x, cow.push_back(x);
	sort(cow.begin(), cow.end());
	for (int i = 0; i < n; i++) pass[go(i)] += 1;

	for (int i = 0; i < n; i++) {
		if (pass[i] == 0) ans += 1;
		if (pass[i] == 1 && pass[go(i)] == 1 && go(go(i)) == i && i < go(i)) ans += 1;
	}
	cout << ans;
	return 0;
}