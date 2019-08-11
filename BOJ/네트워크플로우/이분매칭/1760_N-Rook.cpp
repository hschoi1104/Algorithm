#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
vector<vector<int>>g;
int input[101][101];
int row[101][101];
int col[101][101];
bool chk[10001];
int b[10001];
int n, m, u, v, ans = 0, nodeNum = 0;

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
	scanf("%d %d", &n, &m);
	g.resize(10001);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &input[i][j]);
		}
	}
	//열기준 카운트
	int prev = 2;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		prev = 2;
		for (int j = 1; j <= m; j++) {
			if (input[i][j] == 0 || input[i][j] == 1) {
				if (prev != 0) cnt += 1;
				row[i][j] = cnt;
			}
			if (input[i][j] == 1 || input[i][j] == 0)prev = 0;
			else prev = input[i][j];
		}
	}
	nodeNum = cnt;
	//행기준 카운트
	prev = 2;
	cnt = 0;
	for (int i = 1; i <= m; i++) {
		prev = 2;
		for (int j = 1; j <= n; j++) {
			if (input[j][i] == 0 || input[j][i] == 1) {
				if (prev != 0) cnt += 1;
				col[j][i] = cnt;
			}
			if (input[j][i] == 1 || input[j][i] == 0)prev = 0;
			else prev = input[j][i];
		}
	}
	//그래프 생성
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (input[i][j] == 0) {
				g[row[i][j]].push_back(col[i][j] + 5000);
			}
		}
	}
	for (int i = 1; i <= nodeNum; i++) {
		memset(chk, 0, sizeof(chk));
		if (dfs(i))ans += 1;
	}
	printf("%d\n", ans);
	return 0;
}
