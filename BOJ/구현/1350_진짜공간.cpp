#include <stdio.h>
using namespace std;
typedef long long ll;
ll arr[1001];
int main() {
	ll n, c;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	scanf("%lld", &c);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) continue;
		else {
			if (arr[i] % c == 0) ans += (arr[i] / c)*c;
			else ans += (arr[i] / c + 1)*c;
		}
	}
	printf("%lld\n", ans);

	return 0;
}