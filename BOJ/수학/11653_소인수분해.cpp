#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;
int arr[10000001];
vector<ll>v, ans;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n; cin >> n;
	for (int i = 2; i <= sqrt(n); i++) {
		if (arr[i] == 0) {
			for (int j = i + i; j <= n; j += i) arr[j] = 1;
		}
	}
	for (int i = 2; i <= n; i++) if (arr[i] == 0) v.push_back(i);

	while (n != 1) {
		for (int i = 0; i < v.size(); i++) {
			if (n % v[i] == 0) {
				ans.push_back(v[i]);
				n /= v[i];
				break;
			}
		}
	}
	for (auto it : ans) cout << it << "\n";

	return 0;
}