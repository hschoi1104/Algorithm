#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
int main() {
	int t;
	cin >> t;
	while (t--) {
		set<ll>s, in;
		int n;
		ll x;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x;
			in.insert(x);
		}
		ll temp = (*in.begin()) * (*in.rbegin());
		for (ll i = 2; i * i <= temp; i++) {
			if (temp % i == 0) {
				s.insert(i);
				s.insert(temp / i);
			}
		}
		if (s == in) cout << temp << "\n";
		else cout << -1 << "\n";
	}
	return 0;
}