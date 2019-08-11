#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>a, b;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int k = 0, n; cin >> n;
	vector<int>in(n);
	for (int i = 0; i < n; i++)	cin >> in[i];
	for (int i = in.size() - 1; i > 0; i--) {
		if (in[i - 1] > in[i]) {
			k = i;
			break;
		}
	}
	for (int i = 0; i < k; i++) a.push_back(in[i]);
	for (int i = k; i < n; i++) b.push_back(in[i]);
	vector<int>ans;
	while (a.size()) {
		int cur = a[0], p;
		a.erase(a.begin());
		auto it = lower_bound(b.begin(), b.end(), cur);
		if (it != b.end())p = a.size() + (it - b.begin());
		else p = a.size() + b.size();
		ans.push_back(p);
		b.insert(it,cur);
	}
	cout << ans.size()<<"\n";
	cout << *ans.begin();
	for (int i = 1; i < ans.size(); i++) {
		cout << " " << ans[i];
	}
	return 0;
}