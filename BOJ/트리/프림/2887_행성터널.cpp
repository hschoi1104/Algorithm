#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
vector<p>x, y, z;
vector<vector<p>>g;
priority_queue<p, vector<p>, greater<p>>pq;
int chk[100001], n;
ll a, b, c;
ll prim(ll s) {
	pq.push({ 0,s });
	ll ans = 0;
	while (!pq.empty()) {
		ll cur = pq.top().second;
		ll cost = pq.top().first;
		pq.pop();
		if (chk[cur]) continue;
		else chk[cur] = 1;
		ans += cost;
		for (int i = 0; i < g[cur].size(); i++) {
			int next = g[cur][i].first;
			int ncost = g[cur][i].second;
			if (!chk[next]) pq.push({ ncost , next });
		}
	}
	return ans;
}
void addedge(int i) {
	g[x[i].second].push_back({ x[i + 1].second,abs(x[i + 1].first - x[i].first) }); g[x[i + 1].second].push_back({ x[i].second,abs(x[i + 1].first - x[i].first) });
	g[y[i].second].push_back({ y[i + 1].second,abs(y[i + 1].first - y[i].first) }); g[y[i + 1].second].push_back({ y[i].second,abs(y[i + 1].first - y[i].first) });
	g[z[i].second].push_back({ z[i + 1].second,abs(z[i + 1].first - z[i].first) }); g[z[i + 1].second].push_back({ z[i].second,abs(z[i + 1].first - z[i].first) });
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	g.resize(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		x.push_back({ a,i }); y.push_back({ b,i }); z.push_back({ c,i });
	}
	sort(x.begin(), x.end()); sort(y.begin(), y.end()); sort(z.begin(), z.end());
	addedge(0);
	for (int i = 1; i < n - 1; i++) addedge(i);
	cout << prim(0);
	return 0;
}