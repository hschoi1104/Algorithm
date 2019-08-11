#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int, int>>>v;
int arr[101];
int base[101];
void bfs(int s) {
	queue<pair<int, int>>q;
	q.push({ s,1 });
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		bool chk = false;
		for (int i = 0; i < v[cur.first].size(); i++) {
			int next = v[cur.first][i].first;
			int cost = v[cur.first][i].second;
			q.push({ next,cur.second*cost });
			chk = true;
		}
		if (chk == false) arr[cur.first] += cur.second;
	}
}
int main() {
	int n;
	int m;
	scanf("%d %d", &n, &m);
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,c });
		base[a]++;
	}
	bfs(n);
	for (int i = 1; i <= n; i++) {
		if (base[i] == 0) printf("%d %d\n", i, arr[i]);
	}
}