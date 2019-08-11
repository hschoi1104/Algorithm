#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;
int arr[4000001], ans = 0;
vector<ll>v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n; cin >> n;
	for (int i = 2; i <= sqrt(n); i++) {
		if (arr[i] == 0) {
			for (int j = i + i; j <= n; j += i) arr[j] = 1;
		}
	}
	v.push_back(0);
	for (int i = 2; i <= n; i++) if (arr[i] == 0) v.push_back(i);
	for (int i = 1; i < v.size(); i++) v[i] += v[i - 1];

	for (int i = 1; i < v.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (v[i] - v[j] == n) ans += 1;
			if (v[i] - v[j] > n) break;
		}
	}
	cout << ans;
	return 0;
}