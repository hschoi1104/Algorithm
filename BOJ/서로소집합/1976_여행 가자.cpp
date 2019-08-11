#include <stdio.h>
using namespace std;
int parent[201];
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
	int n, m,x;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &x);
			if (x == 1) merge(i, j);
		}
	}
	int ans = -1;
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		if (i == 0) ans = find(x);
		if (ans != find(x)) {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}