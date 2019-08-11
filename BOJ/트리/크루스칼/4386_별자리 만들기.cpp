#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
#include <math.h>
using namespace std;
typedef pair<double, pair<int, int>>p;
typedef pair<double, double> dp;
priority_queue<p,vector<p>,greater<p>>pq;
vector <dp> star;
int parent[101];

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
double getdist(dp a, dp b) {
	return sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
}
int main() {
	int n;
	double a, b, c;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		parent[i] = i; 
		scanf("%lf %lf", &a, &b);
		star.push_back({ a,b });
	}
	for (int i = 0; i < star.size(); i++) {
		for (int j = 0; j < star.size(); j++) {
			if (i == j) continue;
			pq.push({getdist(star[i],star[j]), {i,j} });
		}
	}
	double ans = 0;
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (find(cur.second.first) != find(cur.second.second)) {
			merge(cur.second.first,cur.second.second);
			ans += cur.first;
		}
	}
	
	printf("%.2lf", ans);
	return 0;
}