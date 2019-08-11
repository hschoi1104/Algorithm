#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int>p;
vector<pair<p, int>>v;
int main() {
	int a, b, c, n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		v.push_back({ {a,b},c });
	}
	int ans = 0;
	int cup[3] = { 0,0,0 };
	for (int j = 0; j < 3; j++) {
		int res = 0;
		cup[0] = cup[1] = cup[2] = 0;
		cup[j] = 1;
		for (int i = 0; i < n; i++) {
			swap(cup[v[i].first.first-1], cup[v[i].first.second-1]);
			if (cup[v[i].second-1] == 1)res += 1;
		}
		ans = max(ans, res);
	}
	cout << ans;
	return 0;
}