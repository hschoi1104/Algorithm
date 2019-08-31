#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
typedef struct node {
	int a, b, c;
};
vector<node>v;
vector<vector<int>>g;
int b[51];
int chk[51];
int dfs(int cur) {
	if (chk[cur]) return 0;
	chk[cur] = 1;
	for (int i = 0; i < g[cur].size(); i++) {
		int next = g[cur][i];
		if (b[next] == 0 || dfs(b[next])) {
			b[next] = cur;
			return 1;
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	g.resize(n + 1);
	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		v.push_back(node{ a,b,c });
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (i > j && v[i].a == v[j].a && v[i].b == v[j].b && v[i].c == v[j].c) continue;
			if (v[i].a >= v[j].a && v[i].b >= v[j].b && v[i].c >= v[j].c) g[i + 1].push_back(j + 1);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(chk, 0, sizeof(chk));
		dfs(i);
		memset(chk, 0, sizeof(chk));
		dfs(i);
	}
	for (int i = 1; i <= 50 && i <= n; i++) if (b[i] == 0) ans += 1;
	cout << ans;
	return 0;
}