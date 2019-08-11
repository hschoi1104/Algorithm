#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pa;
int k, m, p, u, v;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		queue<int>q;
		vector<vector<int>>g;
		vector<pa> temp;
		vector<int>res;
		int indegree[1002];
		scanf("%d %d %d", &k, &m, &p);
		g.resize(m + 2);
		temp.resize(m + 2);
		res.resize(m + 2);
		fill(indegree, indegree + 1000, 0);
		for (int i = 0; i < p; i++) {
			scanf("%d %d", &u, &v);
			g[u].push_back(v);
			indegree[v] += 1;
		}
		for (int i = 1; i <= m; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				res[i] = 1;
			}
			temp[i] = { 0,0 };
		}
		int chk[1002];
		fill(chk, chk + 1000, 0);
		//위상정렬
		while (!q.empty()) {
			int cur = q.front();
			chk[cur] = 1;
			q.pop();
			for (int next : g[cur]) {
				if (chk[next] == 0) {
					indegree[next] -= 1;
					if (res[cur] > temp[next].first) {
						temp[next] = { res[cur],1 };
					}
					else if (res[cur] == temp[next].first) {
						temp[next].second += 1;
					}
					if (indegree[next] == 0) {
						q.push(next);
						res[next] = (temp[next].second >= 2) ? temp[next].first + 1 : temp[next].first;
					}
				}
			}
		}
		printf("%d %d\n", k, res[m]);
		g.clear();
		temp.clear();
		res.clear();
	}
	return 0;
}