#include <stdio.h>
#include <queue>
using namespace std;
typedef pair<int, int> p;
priority_queue<p, vector<p>>pq;
int arr[100001];
int chk[100001];
int find(int u) {
	if (arr[u] == u) return u;
	return arr[u] = find(arr[u]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u != v)arr[v] = u;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	//init
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	//merge
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		merge(a, b);
		find(a);
		find(b);
	}
	//input
	int c, h, k;
	scanf("%d %d %d", &c, &h, &k);

	//chk kingdom
	for (int i = 1; i <= n; i++) {
		chk[find(i)] += 1;
	}
	for (int i = 1; i <= n;i++) {
		if (find(i)!=find(c) && find(i)!=find(h)&& chk[i] > 0) pq.push({ chk[i],i });
	}
	int val = find(c);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (val == find(i)) ans++;
	}

	for (int i = 0; i < k; i++) {
		if (pq.empty()) break;
		auto cur = pq.top();
		pq.pop();
		ans += cur.first;
	}
	printf("%d", ans);
	return 0;
}