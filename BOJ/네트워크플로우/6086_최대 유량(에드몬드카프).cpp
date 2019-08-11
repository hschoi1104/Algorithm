#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>>g;
int flow[52][52];
int capacity[52][52];
int path[52];
int n, c, u, v, ans = 0, s, e;
char a, b;
int ctoi(char c) {
	if ('a' <= c && c <= 'z') return c - 97 + 26;
	else return c - 65;
}
int main() {
	scanf("%d", &n);
	g.resize(53);
	for (int i = 0; i < n; i++) {
		scanf(" %c %c %d", &a, &b, &c);
		u = ctoi(a); v = ctoi(b);
		g[u].push_back(v); g[v].push_back(u);
		capacity[u][v] = capacity[v][u] += c;
	}
	s = ctoi('A'); e = ctoi('Z'); path[s] = -1;
	while (1) {
		int chk[52] = { 0 };
		bool find = false;
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int cur = q.front();
			chk[cur] = 1;
			if (cur == e) {
				find = true;
				break;
			}
			q.pop();
			for (int i = 0; i < g[cur].size(); i++) {
				int next = g[cur][i];
				if (chk[next] != 1 && capacity[cur][next] - flow[cur][next] > 0) {
					path[next] = cur;
					q.push(next);
					chk[next] = 1;
					if (next == e) {
						find = true;
						break;
					}
				}
			}
		}
		if (find == false) break;
		int pos = e; int F = 1001;
		//한 경로에서의 최소 유량을 찾음
		while (1) {
			int prev = path[pos];
			if (prev == -1) break;
			F = min(F, capacity[prev][pos] - flow[prev][pos]);
			pos = prev;
		}
		//F를 flow와 capacity에 업데이트
		pos = e;
		while (1) {
			int prev = path[pos];
			if (prev == -1) break;
			flow[prev][pos] += F;
			flow[pos][prev] -= F;
			pos = prev;
		}
		ans += F;
	}
	printf("%d\n", ans);
	return 0;
}