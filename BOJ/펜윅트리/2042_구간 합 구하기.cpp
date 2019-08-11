#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll>t;
vector<ll>v;
ll sum(int i) {
	ll res = 0;
	while (i > 0) {
		res += t[i];
		i -= (i & -i);
	}
	return res;
}
void update(ll i, ll val) {
	while (i < t.size()) {
		t[i] += val;
		i += (i & -i);
	}
}
int main() {
	int n, m, k;
	ll x, y, z;
	scanf("%d %d %d", &n, &m, &k);
	t.resize(n + 1);
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &v[i]);
		update(i, v[i]);
	}
	for (int i = 1; i <= m + k; i++) {
		scanf("%lld %lld %lld", &x, &y, &z);
		if (x == 1) {
			ll diff = z - v[y];
			v[y] = z;
			update(y, diff);
		}
		else printf("%lld\n", sum(z) - sum(y-1));
	}
}