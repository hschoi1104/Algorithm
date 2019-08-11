#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
vector<vector<int>>v;
int chk[10001];
int ans[10001];
void bfs(int cur) {
	queue<int>q;
	q.push(cur);
	chk[cur] = 1;
	int res = 0;
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		for (int i = 0; i < v[c].size(); i++) {
			int next = v[c][i];
			if (chk[next] ==0) {
				q.push(next);
				chk[next] = 1;
			}
		}
	}
	return;
}
int main() {
	int n, m, a, b, maxval = 0, t = 0;
	scanf("%d %d", &n, &m);
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		memset(chk, 0, sizeof(chk));
		bfs(i);
		int cnt = 0;
		for (int j = 1; j <= n; j++) if (chk[j] == 1) cnt += 1;
		ans[i] = cnt;
		t = max(t, ans[i]);
	}
	for (int i = 1; i <= n; i++) if (ans[i] == t) printf("%d ", i);
	return 0;
}