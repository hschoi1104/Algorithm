#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string.h>
using namespace std;
typedef pair<int, int> p;
vector<vector<int>>g;
int chk[103];
int getdist(p a, p b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
bool bfs(int s,int e) {
	queue<int> q;
	q.push(s);
	chk[s] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == e) return true;
		for (int i = 0; i < g[cur].size(); i++) {
			int next = g[cur][i];
			if (next == e) return true;
			if (chk[next] == 0) {
				chk[next] = 1;
				q.push(next);
			}
		}
	}
	return false;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		vector<p>v;
		int n,a,b;
		scanf("%d", &n);
		g.resize(n + 3);
		for (int i = 0; i < n + 2; i++) {
			scanf("%d %d", &a, &b);
			v.push_back({ a, b });
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = i; j < v.size(); j++) {
				if (i == j) continue;
				if (getdist(v[i], v[j]) <= 1000) {
					g[i].push_back(j); g[j].push_back(i);
				}
			}
		}
		chk[0] = 1;
		if (bfs(0,n+1)==true) printf("happy\n");
		else printf("sad\n");
		g.clear();v.clear();
		memset(chk, 0, sizeof(chk));
	}
	return 0;
}