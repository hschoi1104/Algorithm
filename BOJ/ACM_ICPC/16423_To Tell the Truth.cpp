#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> p;
vector<p>v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = n; i >= 0; i--) {
		int cnt = 0;
		for (auto it = v.begin(); it != v.end(); it++) {
			if (it->first <= i && i <= it->second) cnt += 1;
		}
		if (cnt == i) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}