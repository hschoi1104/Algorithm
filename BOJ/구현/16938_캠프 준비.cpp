#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<int>v;
int n, l, r, x, t, ans = 0, chk[20];
void go(int here, ll sum, int maxval, int minval, int curk, int k) {
	if (curk == k) {
		if (l <= sum && sum <= r && (maxval - minval) >= x) ans += 1;
		return;
	}
	for (int i = here; i < n; i++) {
		if (chk[i]) continue;
		chk[i] = 1;
		go(i, sum + ll(v[i]), max(maxval, v[i]), min(minval, v[i]), curk + 1, k);
		chk[i] = 0;
	}
	return;
}
int main() {

	scanf("%d %d %d %d", &n, &l, &r, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		v.push_back(t);
	}
	//2~n개까지 고름
	for (int i = 2; i <= n; i++) {
		go(0, 0, 0, 999999999, 0, i);
	}
	printf("%d", ans);
	return 0;
}