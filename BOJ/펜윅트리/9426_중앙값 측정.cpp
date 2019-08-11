#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> t;
vector<ll> num;
void update(int i, ll val) {
	while (i < t.size()) {
		t[i] += val;
		i += i & (-i);
	}
}
ll sum(int i) {
	ll ans = 0;
	while (i > 0) {
		ans += t[i];
		i -= i & (-i);
	}
	return ans;
}
int main() {
	ll n, k, x, ans = 0;
	scanf("%lld %lld", &n, &k);
	num.resize(250002);
	t.resize(65537);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &num[i]);
		num[i] += 1;
		update(num[i], 1);
		if (i < k)continue;
		int l = 0, r = 65537;
		while (l + 1 < r) {
			int mid = (l + r) / 2;
			if (sum(mid) >= (k + 1) / 2) {
				r = mid;
			}
			else l = mid;
		}
		ans += r - 1;
		update(num[i - k + 1], -1);
	}
	printf("%lld", ans);
	return 0;
}