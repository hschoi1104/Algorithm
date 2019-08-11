#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
typedef pair<int, int> p;
vector<vector<p>>v;
int visited[100001];
p bfs(int s) {
	memset(visited, 0, sizeof(visited));
	queue<p>q;
	q.push({s,0});
	visited[s] = 1;
	p ans = { 0,0 };
	while (!q.empty()) {
		int cur = q.front().first;
		int cost = q.front().second;
		visited[cur] = 1;
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second;
			if (visited[next] != 1) {
				ans = max(ans, { cost + ncost,next });
				q.push({ next,cost + ncost });
			}
		}
	}
	return ans;
}
int main() {
	int n, x, y, z;
	scanf("%d", &n);
	v.resize(n + 2);

	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		while (1) {
			scanf("%d", &y);
			if (y != -1) {
				scanf("%d", &z);
				v[x].push_back({ y,z });
			}
			else break;
		}
	}

	p temp = bfs(1);
	p res = bfs(temp.second);
	printf("%d", res.first);
	return 0;
}