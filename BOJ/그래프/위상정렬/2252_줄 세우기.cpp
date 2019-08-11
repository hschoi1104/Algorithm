#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>>v;
queue<int>q;
vector<int>ans;
int indegree[32001];
void bfs() {
	while (!q.empty()) {
		int cur = q.front();
		ans.push_back(cur);
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			indegree[next] -= 1;
			if (indegree[next] == 0) q.push(next);
		}
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		indegree[b]+=1;
	}
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) q.push(i);
	}
	bfs();
	printf("%d", ans[0]);
	for (int i = 1; i < ans.size(); i++) printf(" %d", ans[i]);
}