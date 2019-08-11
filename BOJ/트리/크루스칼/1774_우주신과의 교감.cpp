#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<double, pair<ll, ll>>pp;
typedef pair<ll, ll> p;
priority_queue<pp, vector<pp>, greater<pp>>pq;
vector <p> star;
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
double getdist(p a, p b) {
	return sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
}
int main() {
	int n, m;
	ll a, b;
	double c, ans = 0, pre = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		scanf("%lld %lld", &a, &b);
		star.push_back({ a,b });
	}
	for (int i = 0; i < m; i++) {
		scanf("%lld %lld", &a, &b);
		merge(a - 1, b - 1);
	}
	for (int i = 0; i < star.size(); i++) {
		for (int j = 0; j < star.size(); j++) {
			if (i == j) continue;
			pq.push({ getdist(star[i],star[j]), {i,j} });
		}
	}

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (find(cur.second.first) != find(cur.second.second)) {
			merge(cur.second.first, cur.second.second);
			ans += cur.first;
		}
	}

	printf("%.2lf", ans);
	return 0;
}