#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
vector<vector<int>>v;
queue<pair<int, int>>q;
int in[502];
int time[502];
int finish[502];
int visited[502];
void bfs() {
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
	int n, x, a, b;

	scanf("%d", &n);
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		while (cnt += 1) {
			scanf("%d", &x);
			if (x == -1) break;
			if (cnt == 1) time[i] = x;
			else {
				v[x].push_back(i);
				in[i] += 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			q.push({ i,time[i] });
			finish[i] = time[i];
		}
	}
	bfs();
	for (int i = 1; i <= n; i++) printf("%d\n", finish[i]);
	return 0;
}