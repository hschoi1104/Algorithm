#include <iostream>
#include <queue>
#include <vector>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
vector<vector<int>>g;
int level[101],val=0,ans=0;
queue<int>q;
void bfs(int s) {
	q.push(s);
	level[s] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < g[cur].size(); i++) {
			int next = g[cur][i];
			if (level[next] == -1) { q.push(next); level[next] = level[cur] + 1; }
		}
	}
	return;
}
void init() {
	memset(level, -1, sizeof(level));
	g.clear();
	while (!q.empty())q.pop();
	ans = val = 0;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 10;
	FOR(tt, t) {
		int n, c; cin >> n >> c;
		init();
		g.resize(101);
		for (int i = 0; i < n / 2; i++) {
			int a, b; cin >> a >> b;
			g[a].push_back(b);
		}
		bfs(c);
		for(int i=1;i<=100;i++) val = max(val, level[i]);
		for(int i=1;i<=100;i++) if (level[i] == val) ans = max(ans, i);

		cout << "#" << tt + 1 << " " << ans << "\n";
	}
	return 0;
}