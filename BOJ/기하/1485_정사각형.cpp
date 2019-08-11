#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;

vector<p> v;
vector<ll>ans;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		ll a, b;
		for (int i = 0; i < 4; i++) {
			cin >> a >> b;
			v.push_back({ a,b });
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				ans.push_back((v[j].first - v[i].first) * (v[j].first - v[i].first) + (v[j].second - v[i].second) * (v[j].second - v[i].second));
			}
		}
		sort(ans.begin(), ans.end());
		if (ans[0] == ans[1] && ans[1] == ans[2] && ans[2] == ans[3] && ans[4] == ans[5]) cout << "1\n";
		else cout << "0\n";
		v.clear(); ans.clear();
	}
	return 0;
}