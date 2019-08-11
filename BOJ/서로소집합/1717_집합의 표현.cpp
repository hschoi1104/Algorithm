#include <stdio.h>
int parent[1000002];
int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}
void merge(int u, int v) {
	int uu = find(u);
	int vv = find(v);
	if (uu != vv) parent[uu] = vv;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0) {
			merge(b, c);
		}
		else {			if (find(b) == find(c)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;}