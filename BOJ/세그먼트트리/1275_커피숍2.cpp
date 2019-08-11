#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long ll;
vector<ll>seg;
int h = 1;
void update(int i, ll val) {
	int pos = i + h - 1;
	seg[pos] = val;
	while (pos > 1) {
		pos /= 2;
		seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
	}
}
ll query(int L, int R, int node, int nodeL, int nodeR) {
	if (nodeL > R || nodeR < L) return 0;
	else if (L <= nodeL && nodeR <= R) return seg[node];
	int mid = (nodeL + nodeR) / 2;
	return query(L, R, node * 2, nodeL, mid) + query(L, R, node * 2 + 1, mid + 1, nodeR);
}
int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	while (h < n)h <<= 1;
	seg.resize(2 * h);
	for (int i = 0; i < n; i++) {
		ll x;
		scanf("%lld", &x);
		update(i + 1, x);
	}
	for (int i = 0; i < q; i++) {
		int a, b, c;
		ll d;
		scanf("%d %d %d %lld", &a, &b, &c, &d);
		printf("%lld\n", query(min(a, b), max(a, b), 1, 1, h));
		update(c, d);
	}
	return 0;
}