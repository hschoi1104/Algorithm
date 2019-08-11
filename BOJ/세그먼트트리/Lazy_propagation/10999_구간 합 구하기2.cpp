#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll>seg, lazy;
ll h = 1;
void propagation(int idx, int segl, int segr) {
	if (lazy[idx] == 0) return;
	seg[idx] += lazy[idx] * (segr - segl + 1);
	if (segr != segl) {
		lazy[idx * 2] += lazy[idx];
		lazy[idx * 2 + 1] += lazy[idx];
	}
	lazy[idx] = 0;
}
void query_lazy(int l, int r, int idx, int segl, int segr, ll val) {
	propagation(idx, segl, segr);
	if (segr < l || r < segl) return;
	if (l <= segl && segr <= r) {
		seg[idx] += val * (segr - segl + 1);
		if (segr != segl) {
			lazy[idx * 2] += val;
			lazy[idx * 2 + 1] += val;
		}
		return;
	}
	int mid = (segr + segl) / 2;
	query_lazy(l, r, idx * 2, segl, mid, val);
	query_lazy(l, r, idx * 2 + 1, mid + 1, segr, val);
	seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}
void update(int i, ll val) {
	i += h - 1;
	seg[i] = val;
	while (i > 1) {
		i /= 2;
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}
	return;
}
ll query(int l, int r, int idx, int segl, int segr) {
	propagation(idx, segl, segr);
	if (l <= segl && segr <= r) return seg[idx];
	else if (segr < l || r < segl) return 0;
	int mid = (segl + segr) / 2;
	return query(l, r, idx * 2, segl, mid) + query(l, r, idx * 2 + 1, mid + 1, segr);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll a, b, c, d, x, n, m, k; cin >> n >> m >> k;
	while (h < n)h <<= 1;  seg.resize(h * 2); lazy.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		cin >> x;
		update(i, x);
	}
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			cin >> d;
			query_lazy(b, c, 1, 1, h, d);
		}
		else cout << query(b, c, 1, 1, h) << "\n";
	}
	return 0;
}