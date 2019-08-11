#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_NUM 2000000000
using namespace std;
typedef pair<int, int> p;
vector<p>v;
vector<vector<p>>g;
int parent[100001];
int find(int u) {
	if (u == parent[u]) return u;
	else return parent[u] = find(parent[u]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u != v) parent[u] = v;
}
int main() {
	int a, b, n, m; cin >> n >> m;
	for (int i = 0; i < 100001; i++) parent[i] = i;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		merge(a, b);
	}
	g.resize(n + 1);
	int ans = MAX_NUM;
	for (int i = 1; i <= n; i++) g[find(i)].push_back(v[i - 1]);
	for (int i = 1; i < g.size(); i++) {
		if (g[i].size() != 0) {
			int minx = MAX_NUM, miny = MAX_NUM, maxx = 0, maxy = 0;
			for (int j = 0; j < g[i].size(); j++) {
				minx = min(minx, g[i][j].first);
				miny = min(miny, g[i][j].second);
				maxx = max(maxx, g[i][j].first);
				maxy = max(maxy, g[i][j].second);
			}
			ans = min(ans, 2 * ((maxx - minx) + (maxy - miny)));
		}
	}
	cout << ans;
	return 0;
}