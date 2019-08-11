#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
vector<vector<int>>g;
int f[52][52];
int c[52][52];
int level[52];
int work[52];
int INF = 999999999;
int ansflow = 0, s, t;
int n, x, u, v;
char a, b;
//레벨그래프 형성 bfs
bool bfs() {
	memset(level, -1, sizeof(level));
	level[s] = 0;
	queue<int>q;
	q.push(s);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < g[cur].size(); i++) {
			int next = g[cur][i];
			if (level[next] == -1 && c[cur][next] - f[cur][next] > 0) {
				level[next] = level[cur] + 1;
				q.push(next);
			}
		}
	}
	return level[t] != -1;
}
int dfs(int cur,int flow) {
	if (cur == t) return flow;
	for (int &i = work[cur]; i < g[cur].size(); i++) {
		int next = g[cur][i];
		if (level[next] == level[cur] + 1 && c[cur][next] - f[cur][next] > 0) {
			int ret = dfs(next, min(c[cur][next] - f[cur][next], flow));
			if (ret > 0) {
				f[cur][next] += ret;
				f[next][cur] -= ret;
				return ret;
			}
		}
	}
	return 0;
}
int stoi(char ch) {
	if ('A' <= ch && ch <= 'Z') return ch - 'A';
	else return ch - 'a' + 26;
}
int main() {
	scanf("%d", &n);
	g.resize(52);
	for (int i = 0; i < n; i++) {
		scanf(" %c %c %d", &a, &b, &x);
		u = stoi(a); v = stoi(b);
		g[u].push_back(v); g[v].push_back(u);
		c[u][v] += x; c[v][u] += x;
	}
	//레벨 그래프를 싱크까지 생성하지 못할때 까지 실행
	s = stoi('A'), t = stoi('Z');
	while (bfs()) {
		memset(work, 0, sizeof(work));
		//모든 증가경로를 찾아줌
		while (1) {
			int flow = dfs(s, INF);
			if (flow == 0) break;
			ansflow += flow;
		}
	}
	printf("%d", ansflow);
	return 0;
}