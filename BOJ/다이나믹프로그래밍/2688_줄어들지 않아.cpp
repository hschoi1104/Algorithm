#include <stdio.h>
using namespace std;
typedef long long ll;


int main() {
	ll t;
	scanf("%lld", &t);
	while (t--) {
		ll n;
		ll arr[1002][11];
		scanf("%lld", &n);
		if (n == 1) {
			printf("10\n");
			continue;
		}
		ll cnt = 1;
		for (int i = 9; i >= 0; i--) {
			arr[1][i] = cnt++;
		}
		for (int j = 2; j <= n; j++) {
			arr[j][9] = 1;
			for (int i = 8; i >= 0; i--) {
				arr[j][i] = arr[j][i + 1] + arr[j - 1][i];
			}
		}
		ll ans = 0;
		for (int i = 0; i <= 9; i++) {
			ans += arr[n - 1][i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}