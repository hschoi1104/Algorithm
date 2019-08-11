#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
vector<p>seg;
ll ans = 0;
ll h = 1;
void update(ll i, ll val) {
	i += h - 1;
	seg[i] = { val,i };
	while (i > 1) {
		i /= 2;
		if (seg[i * 2].first <= seg[i * 2 + 1].first) seg[i] = seg[i * 2];
		else seg[i] = seg[i * 2 + 1];
	}
	return;
}
p query(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return { LLONG_MAX,LLONG_MAX };
	else if (L <= nodeL && nodeR <= R) return seg[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return min(query(L, R, nodeNum * 2, nodeL, mid), query(L, R, nodeNum * 2 + 1, mid + 1, nodeR));
}
void go(int s, int e) {
	if (s == e) {
		ans = max(ans, seg[e + h - 1].first);
		return;
	}
	else if (s > e) return;
	p qval = query(s, e, 1, 1, h);
	ans = max(ans, seg[qval.second].first * ll(e - s + 1));
	go(s, qval.second - h);
	go(qval.second - h + 2, e);
	return;
}
int main() {
	ll n;
	while (1) {
		scanf("%lld", &n);
		if (n == 0) return 0;
		h = 1;
		ans = 0;
		while (h < n)h <<= 1;
		seg.resize(h * 2);
		for (int i = 0; i < 2 * h; i++)	seg[i] = { LLONG_MAX,LLONG_MAX };
		for (ll i = 1; i <= n; i++) {
			ll x;
			scanf("%lld", &x);
			update(i, x);
		}
		go(1, n);
		printf("%lld\n", ans);
		seg.clear();
	}
}