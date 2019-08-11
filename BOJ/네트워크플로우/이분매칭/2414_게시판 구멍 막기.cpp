#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
vector<vector<int>>g;
char input[51][51];
int row[51][51];
int col[51][51];
bool chk[3001];
int b[3001];
int n, m, u, v, ans = 0,nodeNum=0;

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
	g.resize(3001);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %1c", &input[i][j]);
		}
	}
	//열기준 카운트
	char prev = '.';
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		prev = '.';
		for (int j = 1; j <= m; j++) {
			if (input[i][j] == '*') {
				if (prev == '.') cnt += 1;
				row[i][j] = cnt;
			}
			prev = input[i][j];
		}
	}
	nodeNum = cnt;
	//행기준 카운트
	prev = '.';
	cnt = 0;
	for (int i = 1; i <= m; i++) {
		prev = '.';
		for (int j = 1; j <= n; j++) {
			if (input[j][i] == '*') {
				if (prev == '.') cnt += 1;
				col[j][i] = cnt;
			}
			prev = input[j][i];
		}
	}
	//그래프 생성
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (input[i][j] == '*') {
				g[row[i][j]].push_back(col[i][j] + 1500);
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
