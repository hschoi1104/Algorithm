#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	ll n, a = 1; cin >> n;
	for (ll i = 1; i < n; i++) a = ((2 * i + 1) * a) % (int(1e9) + 9);
	cout << a;
	return 0;
}