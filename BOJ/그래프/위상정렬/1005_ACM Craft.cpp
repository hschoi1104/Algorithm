#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
vector<vector<int>>v;
queue<pair<int,int>>q;
int in[1002];
int time[1002];
int finish[1002];
int visited[1002];
void bfs(int e) {
	while (!q.empty()) {
		auto cur = q.front();
		visited[cur.first] = 1;
		q.pop();
		for (int i = 0; i < v[cur.first].size(); i++) {
			int next = v[cur.first][i];
			in[next]--;
			finish[next] = max(finish[next], cur.second + time[next]);
			if (visited[next] == 0 && in[next] == 0) {
				q.push({ next, finish[next] });
			}
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k,x,a,b,e;
		memset(in, 0, sizeof(in));
		memset(time, 0, sizeof(time));
		memset(finish, 0, sizeof(finish));
		memset(visited, 0, sizeof(visited));
		v.clear();
		scanf("%d %d", &n, &k);
		v.resize(n + 1);
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			time[i + 1] = x;
		}
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			in[b] += 1;
		}
		scanf("%d", &e);
		for (int i = 1; i <= n; i++) if (in[i] == 0) q.push({i,time[i]});
		bfs(e);
		printf("%d\n", finish[e]);
	}
	return 0;
}