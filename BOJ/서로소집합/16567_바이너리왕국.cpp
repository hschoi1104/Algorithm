#include <stdio.h>
int parent[1000001];
int path[1000001];
int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	parent[u] = v;
	return;
}
int main() {
	int n, m, x, y, ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &path[i]);
		parent[i] = i;
		if (path[i] == 1) ans += 1;
		if (path[i - 1] == 1 && path[i] == 1) {
			merge(i - 1, i);
			ans -= 1;
		}
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		if (x == 0) {
			printf("%d\n", ans);
		}
		else {
			scanf("%d", &y);
			if (path[y] == 1) continue;
			else {
				ans += 1;
				path[y] = 1;
				//аб
				if (y > 0 && path[y - 1] == 1) {
					if (find(y - 1) != find(y)) {
						merge(y - 1, y);
						ans -= 1;
					}
				}
				//©Л
				if (y + 1 <= n && path[y + 1] == 1) {
					if (find(y) != find(y + 1)) {
						merge(y, y + 1);
						ans -= 1;
					}
				}
			}
		}
	}
	
	return 0;
}