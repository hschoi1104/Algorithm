#include <stdio.h>
#include <string.h>
#include <queue>
#include <functional>
#include <math.h>
using namespace std;
int parent[501], cnt = 0;
typedef pair<double, pair<int, int>> pp;
struct point {
	int x; int y;
};
point arr[501];
int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	cnt--;
	parent[u] = v;
}
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		for (int i = 0; i <= 500; i++) {
			point t = { 0,0 };
			arr[i] = t;
			parent[i] = i;
		}
		int s, p; scanf("%d %d", &s, &p);
		for (int i = 0; i < p; i++) scanf("%d %d", &arr[i].x, &arr[i].y);
		priority_queue<pp> pq;
		for (int i = 0; i < p; i++) {
			for (int j = i+1; j < p; j++) {
				double dist = sqrt((arr[i].x - arr[j].x) * (arr[i].x - arr[j].x) + (arr[i].y - arr[j].y) * (arr[i].y - arr[j].y));
				pq.push({ -dist,{i,j} });
			}
		}
		cnt = p - s;
		double val;
		while (cnt) {
			val = pq.top().first;
			merge(pq.top().second.first, pq.top().second.second);
			pq.pop();
		}
		printf("%.2lf\n", -val);
	}
	return 0;
}