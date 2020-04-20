#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int dist[2010], ans, n, k, m;

struct node {
	int s, e, w;
};
vector<node>v;

bool cmp(const node& a, const node& b) {
	if (a.e == b.e) return a.s < b.s;
	else return a.e < b.e;
}
int main() {
	FIO;
	cin >> n >> k >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < m; i++) {
		auto cur = v[i];
		int tmp = INT_MAX;
		for (int j = cur.s; j < cur.e; j++) tmp = min(tmp, k - dist[j]);
		tmp = min(tmp, cur.w);
		ans += tmp;
		for (int j = cur.s; j < cur.e; j++) dist[j] += tmp;
	}
	cout << ans;
	return 0;
}