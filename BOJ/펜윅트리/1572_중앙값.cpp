#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll>t;
vector<ll>v;
void update(int i, ll val) {
	while (i < t.size()) {
		t[i] += val;
		i += i & (-i);
	}
}
ll sum(int i) {
	ll res = 0;
	while (i > 0) {
		res += t[i];
		i -= i & (-i);
	}
	return res;
}

int main() {
	int n, k, x;
	ll ans = 0;
	scanf("%d %d", &n, &k);
	t.resize(250002);
	v.resize(250002);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &v[i]);
		v[i] += 1;
		update(v[i], 1);
		if (i < k) continue;
		int l = 1, r = 250000, mid = 0, ret = 0;
		while (l <= r) {
			mid = (l + r) / 2;
			if (sum(mid) >= (k + 1) / 2) {
				r = mid - 1;
				ret = mid;
			}
			else {
				l = mid + 1;
			}
		}
		ans += ret - 1;
		update(v[i - k + 1], -1);
	}
	printf("%lld\n", ans);
	return 0;
}