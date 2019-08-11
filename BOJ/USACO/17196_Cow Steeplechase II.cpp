#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
vector<pair<pair<p, p>, ll>>v;
ll ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
	ll op = a.first * b.second + b.first * c.second + c.first * a.second;
	op -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if (op > 0)return 1;
	else if (op == 0)return 0;
	else return -1;
}
int chkIntersect(pair<pair<ll, ll>, pair<ll, ll>> x, pair<pair<ll, ll>, pair<ll, ll>> y) {
	pair<ll, ll> a = x.first;
	pair<ll, ll> b = x.second;
	pair<ll, ll> c = y.first;
	pair<ll, ll> d = y.second;
	ll ab = ccw(a, b, c) * ccw(a, b, d);
	ll cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (a > b)swap(a, b);
		if (c > d)swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll a, b, c, d, n; cin >> n;
	v.push_back({ {{0,0},{0,0}},0 });

	for (int i = 1; i <= n; i++) {
		cin >> a >> b >> c >> d;
		if (a > c) {
			swap(a, c); swap(b, d);
		}
		v.push_back({ {{a,b},{c,d}},i });
	}
	sort(v.begin(), v.end());
	int s = 1;
	int cnt[100001] = { 0 };
	for (int i = 1; i < v.size(); i++) {
		auto cur = v[i];
		for (int j = i - 1; j > 0 && j >= i - 2; j--) {
			if (chkIntersect(v[i].first, v[j].first)) {
				cnt[i] += 1;
				cnt[j] += 1;
			}
		}
	}
	p ans{ 0,0 };
	for (int i = 1; i < v.size(); i++) {
		if (ans.first < cnt[i]) ans = { cnt[i],v[i].second };
		if (ans.first == cnt[i] && ans.second > v[i].second) ans.second = v[i].second;
	}
	cout << ans.second;
	return 0;
}