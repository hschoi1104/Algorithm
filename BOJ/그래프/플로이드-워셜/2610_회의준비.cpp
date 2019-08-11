#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int g[102][102];
vector<vector<int>>graph;
vector<int>ret;
vector<vector<int>>ans;
int INF = 999999999;
int chk[102];
int main() {
	int n, m, u, v;
	scanf("%d %d", &n, &m);
	graph.resize(n + 2);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			g[i][j] = (i == j) ? 0 : INF;
		}
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		g[u][v] = g[v][u] = 1;
		graph[u].push_back(v); graph[v].push_back(u);
	}
	//플로이드
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (g[i][j] > g[i][k] + g[k][j])
					g[i][j] = g[i][k] + g[k][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (chk[i] != 0) continue;
		vector<int>temp;
		temp.push_back(i);
		chk[i] = 1;
		for (int j = 0; j <= n; j++) {
			if (chk[j] == 0 && g[i][j] != INF) {
				temp.push_back(j);
				chk[j] = 1;
			}
		}
		ans.push_back(temp);
	}
	for (int i = 0; i < ans.size(); i++) {
		sort(ans[i].begin(), ans[i].end());
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		pair<int, int> res = { INF,INF };
		for (int j = 0; j < ans[i].size(); j++) {
			int nu = ans[i][j];
			int sum = 0;
			for (int k = 0; k < ans[i].size(); k++) {
				int nv = ans[i][k];
				sum = max(sum, g[nu][nv]);
			}
			if (res.first > sum) res = { sum,nu };
		}
		ret.push_back(res.second);
	}
	sort(ret.begin(), ret.end());
	for (int n : ret) printf("%d\n", n);
	return 0;
}