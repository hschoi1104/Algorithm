#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> v;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll a, g; cin >> a >> g;
	ll val = gcd(a, g);
	for (ll i = 1; i * i <= val; i++) {
		if (val % i == 0) {
			v.push_back(i);
			if (val / i == i) continue;
			v.push_back(val / i);
		}
		else continue;
	}
	sort(v.begin(), v.end());
	for (auto it : v) cout << it << " " << a / it << " " << g / it << "\n";
	return 0;
}