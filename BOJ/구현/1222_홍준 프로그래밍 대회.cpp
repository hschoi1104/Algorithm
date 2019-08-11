#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll>v;
ll arr[2000001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll x, n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
		arr[x] += 1;
	}
	ll ans = 0;
	for (ll i = 1; i <= 2000000; i++) {
		int fina = 0;
		for (ll j = i; j <= 2000000; j += i) {
			if (arr[j] != 0) {
				fina += arr[j];
			}
		}
		if (fina >= 2) ans = max(fina * i, ans);
	}
	cout << ans;
	return 0;
}