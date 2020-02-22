#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, cnt = 0;
vector<int>v;
bool go(int sum) {
	if (sum == n) cnt += 1;
	if (cnt == k) return true;
	for (int i = 1; i < 4; i++) {
		if (sum + i <= n && go(sum + i)) {
			v.push_back(i);
			return true;
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	go(0);
	if (v.size()) {
		for (int it = v.size() - 1; it > 0; it--) cout << v[it] << "+";
		cout << v[0];
	}
	else cout << -1;
	return 0;
}