#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, ans = 0; cin >> n;
	for (int i = 0; i < n; i++) {
		int t; cin >> t; ans = max(ans, t);
	}
	cout << ans;
	return 0;
}