#include <iostream>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll d[100002], f = 1;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n; cin >> n;
	d[1] = 0, d[0] = 1;
	for (ll i = 2; i <= n; i++) {
		f *= i, f %= MOD;
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]) % MOD;
	}

	cout << (f * d[n]) % MOD;
	return 0;
}