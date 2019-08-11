#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
multiset<int>s;
int main() {
	int n, x; cin >> n;
	vector<int>a(n); vector<int>ans(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		cin >> x; s.insert(x);
	}
	for (int i = 0; i < n; i++) {
		auto it = s.lower_bound(n - a[i]);
		if (it == s.end())
			it = s.begin();
		ans[i] = (a[i] + *it) % n;
		s.erase(it);
	}
	for (auto it : ans) cout << it << " ";
	return 0;

}