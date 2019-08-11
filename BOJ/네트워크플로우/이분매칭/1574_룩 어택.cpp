#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
vector<vector<int>>g;
int input[301][301];
bool chk[601];
int b[601];
int n, m, u, v, k, ans = 0, nodeNum = 0;

int dfs(int cur) {
	if (chk[cur]) return 0;
	chk[cur] = 1;
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
	scanf("%d %d %d", &n, &m, &k);
	g.resize(601);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &u, &v);
		input[u][v] = 1;
	}
	//그래프 생성
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (input[i][j] == 0) {
				g[i].push_back(j + 300);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (g[i].size() == 0) continue;
		memset(chk, 0, sizeof(chk));
		if (dfs(i))ans += 1;
	}
	printf("%d\n", ans);
	return 0;
}
