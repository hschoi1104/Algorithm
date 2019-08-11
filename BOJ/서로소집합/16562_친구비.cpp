#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
p parent[10001];
int chk[10001];
int INF = 1e9;
ll ans = 0;
int find(int u) {
	if (parent[u].first == u) return u;
	return parent[u].first = find(parent[u].first);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	parent[u].first = v;
	return;
}
int main() {
	int n, m, k, x, y;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		parent[i] = { i,x };
		chk[i] = INF;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		merge(x, y);
	}
	for (int i = 1; i <= n; i++) {
		chk[find(i)] = min(chk[find(i)], parent[i].second);
	}
	for (int i = 1; i <= n; i++) {
		if (chk[i] != INF) ans += chk[i];
	}
	if (ans <= k) printf("%lld", ans);
	else printf("Oh no");
	return 0;
}