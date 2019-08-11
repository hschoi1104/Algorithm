#include <stdio.h>
#include <algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int main() {
	int t, cnt = 1;
	scanf("%d", &t);
	while (t--) {
		vector<ll>v;
		ll ans = 0, x;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lld", &x);
			v.push_back(x);
		}
		ll val = v[v.size() - 1];
		for (int i = v.size() - 1; i >= 0; i--) {
			if (v[i] < val) ans += val - v[i];
			else val = v[i];
		}
		printf("#%d %lld\n", cnt++, ans);
		v.clear();
	}
	return 0;
}