#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0,x; i < n; i++) {
		cin >> x; v.push_back(x);
	}
	sort(v.begin(),v.end());
	int ans = v.size();
	for (int i = 0; i < n; i++) {
		int idx = (upper_bound(v.begin(), v.end(),v[i]) - v.begin());
		ans = min(ans, min((int)(v[i] + (v.size() - idx)), v[v.size() - 1]));
	}
	cout << ans;
	return 0;
}