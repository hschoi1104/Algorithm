#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
typedef pair<int, pair<int, int>>p;
priority_queue<p,vector<p>,greater<p>>pq;
int parent[1001];

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
	int n, m,a,b,c;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		parent[i] = i; 
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		pq.push({ c,{a,b} });
	}
	int ans = 0;
	
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (find(cur.second.first) != find(cur.second.second)) {
			merge(cur.second.first,cur.second.second);
			ans += cur.first;
		}
	}
	
	printf("%d", ans);
	return 0;
}