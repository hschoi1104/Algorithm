#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int in[10010];
int out[10010];
int finish[10010];
int visited[10010];
vector<vector<pair<int, int>>>v;
vector<vector<pair<int, int>>>r;
queue <int>q;
int ans = 0;
void bfs(int s,int e) {
	q.push(s);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int cost = v[cur][i].second;
			in[next] -= 1;
			finish[next] = max(finish[next], finish[cur] + cost);
			if (in[next] == 0) q.push(next);
		}
	}
}
void bfss(int s, int e) {
	q.push(s);
	visited[s] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < r[cur].size(); i++) {
			int next = r[cur][i].first;
			int cost = r[cur][i].second;
			if (visited[cur] && (finish[cur] - finish[next] == cost)) {
				ans+=1;
				visited[next] = 1;
			}
			out[next]--;
			if (out[next] == 0) q.push(next);
		}
	}
}
int main() {
	int n, m, s, e;
	scanf("%d %d ", &n, &m);
	v.resize(n + 1);
	r.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,c });
		r[b].push_back({ a,c });
		in[b] += 1;
		out[a] += 1;
	}
	scanf("%d %d", &s, &e);
	bfs(s,e);
	printf("%d\n", finish[n]);
	bfss(e, s);
	printf("%d\n", ans);
	return 0;
}