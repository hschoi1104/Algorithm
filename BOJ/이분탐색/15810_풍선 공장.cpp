#include <stdio.h>
#include <limits.h>
using namespace std;
typedef long long ll;
ll arr[1000001];
int main() {
	ll n, m;
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	ll left = 0;
	ll right = LLONG_MAX;
	while (left + 1 < right) {
		ll mid = (left + right) / 2;
		ll cnt = 0;
		for (int i = 0; i < n; i++) {
			if (cnt >= m)break;
			cnt += mid / arr[i];
		}
		if (cnt >= m) {
			right = mid;
		}
		else {
			left = mid;
		}
	}
	printf("%lld\n", right);
	return 0;
}