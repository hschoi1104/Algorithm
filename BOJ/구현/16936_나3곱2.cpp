#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
map<ll, bool>m;
ll ans[101], idx = 0, n;
void go(ll p, int depth) {
	ans[depth] = p;
	if (ans[n - 1] != 0) return;
	if (p % 3 == 0) {
		auto it = m.find(p / 3);
		if (it != m.end() && it->second == false) {
			m[it->first] = true;
			go(it->first, depth + 1);
			m[it->first] = false;
		}
	}
	if (ans[n-1] != 0) return;
	auto it = m.find(p * 2);
	if (it != m.end() && it->second == false) {
		m[it->first] = true;
		go(it->first, depth + 1);
		m[it->first] = false;
	}
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x; m.insert({ x,false });
	}
	for (auto it : m) {
		m[it.first] = true;
		go(it.first, 0);
		m[it.first] = false;
		if (ans[n - 1] != 0) break;
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " ";
	return 0;
}