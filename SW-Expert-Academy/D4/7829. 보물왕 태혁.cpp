#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	for (int tt = 0; tt < t; tt++) {
		int n, ans = 0; cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		sort(v.begin(), v.end());
		ans = *v.begin() * *v.rbegin();
		cout << '#' << tt + 1 << " " << ans << "\n";
	}
	return 0;
}