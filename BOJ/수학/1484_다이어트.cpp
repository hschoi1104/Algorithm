#include <iostream>
#include <set>
#include <math.h>
using namespace std;
typedef long long ll;
set<ll>s;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll g; cin >> g;
	for (ll c = sqrt(g) - 1; c <= 50000; c++) {
		ll tt = c * c - g;
		if (ceil(sqrt(tt)) == sqrt(tt) && (c * c - tt) == g && c * c - g != 0) s.insert(c);
	}
	if (s.size() == 0) cout << "-1";
	else {
		for (auto it : s) cout << it << "\n";
	}
	return 0;
}