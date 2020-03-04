#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
set<ll>m;
vector<ll>v;
ll n, x;
void go(ll p, int depth) {
	if (depth == n) {
		for (auto it : v) cout << it << " ";
		return;
	}
	if (p % 3 == 0 && m.find(p / 3) != m.end()) {
		v.push_back(p / 3);
		go(p / 3, depth + 1);
		v.pop_back();
	}
	if (m.find(p * 2) != m.end()) {
		v.push_back(p * 2);
		go(p * 2, depth + 1);
		v.pop_back();
	}
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x; m.insert(x);
	}
	for (auto it : m) {
		v.push_back(it);
		go(it, 1);
		v.pop_back();
	}

	return 0;
}