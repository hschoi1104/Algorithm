#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
vector<p>v;
int chk[100001];
bool cmp(p a, p b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	else return a.first < b.first;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b, n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a - b,a + b });
	}
	sort(v.begin(), v.end(), cmp);
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (chk[i]) continue;
		ans += 1;
		int f = v[i].first;
		int b = v[i].second;
		for (int j = i; j < v.size(); j++) {
			if (v[j].second <= b) chk[j] = 1;
			else continue;
		}
	}
	cout << ans;
	return 0;
}