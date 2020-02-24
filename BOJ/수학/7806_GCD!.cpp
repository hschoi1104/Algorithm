#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (1) {
		ll n, k, ans = 1; cin >> n >> k;
		if (cin.eof()) break;
		for (ll i = 2; i * i <= k; i++) {
			ll kcnt = 0, mcnt = 0;
			while (k % i == 0) {
				kcnt++;
				k /= i;
			}
			if (kcnt != 0) {
				for (ll j = i; j <= n; j *= i) {
					mcnt += n / j;
				}
				for (ll j = 0; j < min(kcnt, mcnt); j++) ans *= i;
			}
			//***
			if (k < i) break;
			//***
		}
		//***
		if (k > 1 && k <= n) ans *= k;
		cout << ans << "\n";
		//***
	}
	return 0;
}
