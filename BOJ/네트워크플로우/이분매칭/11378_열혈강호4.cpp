#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector<vector<int>>g;
int b[1001], chk[1001];
int dfs(int cur) {
	if (chk[cur] == 1) return 0;
	chk[cur] += 1;
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
	int n, m, k; cin >> n >> m >> k;
	g.resize(n + 1);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		for (int j = 0; j < a; j++) {
			int b; cin >> b;
			g[i + 1].push_back(b);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(chk, 0, sizeof(chk));
		ans += dfs(i);
	}
	memset(chk, 0, sizeof(chk));
	for (int i = 1; i <= n && k != 0; i++) {
		while (k != 0 && dfs(i)) {
			memset(chk, 0, sizeof(chk));
			ans += 1, k -= 1;
		}
	}
	cout << ans;
	return 0;
}