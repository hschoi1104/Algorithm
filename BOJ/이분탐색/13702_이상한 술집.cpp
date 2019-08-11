#include <stdio.h>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef long long ll;
ll arr[100001];
int main() {
	ll n, k,ans=0;
	scanf("%lld %lld", &n, &k);
	for (int i = 0; i < n; i++)scanf("%lld", &arr[i]);
	ll left = 0, right = INT_MAX;
	while (left+1 < right) {
		ll mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += arr[i] / mid;
		}
		if (cnt < k) {
			right = mid;
		}
		else {
			left = mid;
			ans = max(ans, mid);
		}
	}
	printf("%lld", ans);

	return 0;
}