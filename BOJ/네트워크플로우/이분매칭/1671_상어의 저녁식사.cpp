#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
typedef pair<pair<int, int>, int> node;
vector<vector<int>>g;
vector<node>shark;
int path[150];
int chk[150];
int b[150];
int INF = 999999999;
int r, u, v, n, m, x, s = 0, t = 101, ans = 0, a, f, d;
int dfs(int cur) {
	if (chk[cur]) return 0;
	chk[cur] += 1;
	for (int i = 0; i < g[cur].size(); i++) {
		int next = g[cur][i];
		if (b[next] == 0 || dfs(b[next]) == 1) {
			b[next] = cur;
			return 1;
		}
	}
	return 0;
}
int main() {
	scanf("%d", &n);
	g.resize(105);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &f, &d);
		node temp = { {a,f},d };
		shark.push_back(temp);
	}
	for (int i = 0; i < shark.size(); i++) {
		for (int j = 0; j < shark.size(); j++) {
			if (i == j) continue;
			if (shark[i].first.first == shark[j].first.first && shark[i].first.second == shark[j].first.second && shark[i].second == shark[j].second) {
				if (i < j) g[i + 1].push_back(j + 51);
				else continue;
			}
			else if (shark[i].first.first >= shark[j].first.first && shark[i].first.second >= shark[j].first.second && shark[i].second >= shark[j].second) {
				g[i + 1].push_back(j + 51);
			}

		}
	}
	for (int i = 1; i <= n; i++) {
		memset(chk, 0, sizeof(chk));
		dfs(i);
		memset(chk, 0, sizeof(chk));
		dfs(i);
	}
	for (int i = 51; i <= n + 50; i++) if (b[i] == 0) ans += 1;
	printf("%d", ans);
	return 0;
}