#include <stdio.h>
typedef long long ll;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		ll n, k, cnt = 0;
		scanf("%lld %lld", &n, &k);
		while (n) {
			if (n % k == 0) {
				cnt += 1;
				n /= k;
			}
			else {
				cnt += n - n / k * k;
				n = n / k * k;
			}
		}
		printf("%lld\n", cnt);
	}
	return 0;
}