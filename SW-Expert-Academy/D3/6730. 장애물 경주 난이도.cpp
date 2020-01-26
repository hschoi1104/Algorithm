#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		int n; cin >> n;
		vector<int>v;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			v.push_back(x);
		}
		int d1=0, d2=0;
		for (int i = 0; i < v.size(); i++) {
			if (i != v.size() - 1 && v[i]<=v[i+1]) d1 = max(d1, v[i + 1] - v[i]);
			if (i != 0 && v[i - 1] >= v[i]) d2 = max(d2, v[i - 1] - v[i]);
		}
		cout << "#" << tt << " " << d1 << " " << d2 << "\n";
	}
	return 0;
}