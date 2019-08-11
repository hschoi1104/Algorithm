#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<int>>g;
int indegree[500002];
int chk[500002];
void bfs(int c) {
	queue<int>q;
	q.push(1);
	chk[1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < g[cur].size(); i++) {
			int next = g[cur][i];
			if (chk[next] == 0) {
				chk[next] = chk[cur] + 1;
				q.push(next);
			}
		}
	}
}
int main() {
	int n, a, b;
	scanf("%d", &n);
	g.resize(n + 1);
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d", &a, &b);
		g[a].push_back(b); g[b].push_back(a);
		indegree[a] += 1; indegree[b] += 1;
	}
	bfs(1);
	int sum = 0;
	for (int i = 2; i <= n; i++) if (indegree[i] == 1) sum += (chk[i]-1);
	if (sum % 2 == 0) printf("No");
	else printf("Yes");
	return 0;
}