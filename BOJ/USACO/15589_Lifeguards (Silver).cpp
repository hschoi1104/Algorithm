#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
vector<p>v;
ll e = 0, s = -1;
ll len = 0;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		v.push_back({ a,b - 1 });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		if (i == 0) s = v[i].first;
		else if (e < v[i].first) {
			len += e - s + 1;
			s = v[i].first;
		}
		e = max(e, v[i].second);
		if (i == v.size() - 1) len += e - s + 1;
	}
	ll time = 1000000001;
	e = v[0].second;
	for (int i = 0; i < v.size(); i++) {
		ll ss = v[i].first, ee = v[i].second;
		if (i != 0)ss = max(v[i].first, e);
		if (i != v.size() - 1)ee = min(v[i + 1].first, v[i].second);
		e = max(e, v[i].second+1);
		if (ee - ss + 1 > 0)time = min(time, ee - ss);
		else {
			time = 0;
			break;
		}
	}
	cout << len - time;
	return 0;
}
