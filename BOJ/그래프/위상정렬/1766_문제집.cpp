#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include<functional>
using namespace std;
vector<vector<int>>v;
vector<int>ans;
priority_queue<int,vector<int>,greater<int>>pq;
int visited[32002];
int indegree[32002];
void bfs() {
	while (!pq.empty()) {
		int cur = pq.top();
		visited[cur] = 1;
		ans.push_back(cur);
		pq.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			indegree[next] -= 1;
			if (visited[next] == 0 && indegree[next] == 0) pq.push(next);
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
		indegree[b] += 1;
	}
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) pq.push(i);
	}
	bfs();
	printf("%d", ans[0]);
	for (int i = 1; i < ans.size(); i++) printf(" %d", ans[i]);
}