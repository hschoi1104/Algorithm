#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long ll;
ll dp[101][11][1 << 11];
ll ans = 0, n;

ll go(ll cur, ll val, ll chk) {
	if (val < 0 || val>9) return 0;
	if (cur == 1) {
		if ((chk | (1 << val)) == ((1 << 10) - 1)) return 1;
		else return  0;
	}

	ll & ret = dp[cur][val][chk];
	if (ret != -1) return ret;

	return ret = (go(cur - 1, val + 1, chk | (1 << val)) + go(cur - 1, val - 1, chk | (1 << val))) % 1000000000;
}
int main() {
	scanf("%lld", &n);
	memset(dp, -1, sizeof(dp));
	for (ll i = 1; i < 10; i++) {
		ans = (ans + go(n, i, 0)) % 1000000000;
	}
	printf("%lld", ans);
	return 0;
}
