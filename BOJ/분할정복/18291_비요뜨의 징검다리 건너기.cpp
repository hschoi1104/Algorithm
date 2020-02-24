#include <iostream>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll go(int n) {
	if (n == 1|| n == 0) return 2;
	ll tmp = go(n / 2);
	if (n % 2) return (tmp * tmp * 2) % MOD;
	return (tmp * tmp) % MOD;
}
int main() {
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		if (n == 1 || n == 2)cout << "1" << "\n";
		else cout << go(n - 2) << "\n";
	}
	return 0;
}