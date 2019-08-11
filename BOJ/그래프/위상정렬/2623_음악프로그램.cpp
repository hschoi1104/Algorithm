#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>>v;
queue<int>q;
vector<int>ans;
int visited[1002];
int indegree[1002];
void bfs() {
	while (!q.empty()) {
		int cur = q.front();
		visited[cur] = 1;
		ans.push_back(cur);
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			indegree[next] -= 1;
			if (visited[next] == 0 && indegree[next] == 0) q.push(next);
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	v.resize(n + 1);
	cin.ignore();
	for (int i = 0; i < m; i++) {
		int x,y,s;
		scanf("%d", &s);
		scanf("%d", &x);
		for (int j = 0; j < s - 1; j++) {
			scanf("%d", &y);
			v[x].push_back(y);
			indegree[y]++;
			x = y;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) q.push(i);
	}
	bfs();
	if (ans.size() == n) for (int i = 0; i < ans.size(); i++)cout << ans[i] << '\n';
	else printf("0\n");
}