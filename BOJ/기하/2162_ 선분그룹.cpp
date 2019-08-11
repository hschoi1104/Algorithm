#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
int par[3001];
int ans[3001];
vector < pair<p, p> > v;
int find(int u) {
	if (u == par[u]) return u;
	return par[u] = find(par[u]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u < v)par[v] = u;
	else par[u] = v;
}
int ccw(p a, p b, p c) {
	int res = (a.first * b.second + b.first * c.second + c.first * a.second) - (b.first * a.second + c.first * b.second + a.first * c.second);
	if (res > 0) return 1;
	else if (res < 0) return -1;
	else return 0;
}
bool isIntersect(p a, p b, p c, p d) {
	ll ccwA = ccw(a, b, c) * ccw(a, b, d);
	ll ccwB = ccw(c, d, a) * ccw(c, d, b);
	if (ccwA == 0 && ccwB == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return a <= d && c <= b;
	}
	return ccwA <= 0 && ccwB <= 0;
}
int main() {
	int a, b, c, d, n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d;
		par[i] = i;
		v.push_back({ {a,b},{c,d} });
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (i == j) continue;
			int res = isIntersect(v[i].first, v[i].second, v[j].first, v[j].second);
			if (res) merge(i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		par[i] = find(i);
		ans[par[i]] += 1;
	}
	int cnt = 0;
	int m_val = 0;
	for (int i = 0; i < n; i++) {
		if (ans[i] != 0) {
			cnt += 1;
			m_val = max(m_val, ans[i]);
		}
	}
	cout << cnt << "\n";
	for (int i = 0; i < n; i++) if (ans[i] == m_val) {
		cout << ans[i];
		break;
	}
	return 0;
}