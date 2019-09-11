#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
typedef long long ll;
vector<ll>a, b;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) { ll x; cin >> x; a.push_back(x); }
	for (int i = 0; i < n; i++) { ll x; cin >> x; b.push_back(x); }
	a.push_back(LLONG_MAX); b.push_back(LLONG_MAX);
	
	for (int i = 0; i < n; i++) {
		int temp = upper_bound(b.begin(), b.end(), a[i])-b.begin();
		if (temp <= i) cout << "0 ";
		else cout << temp - i - 1<<" ";
	}
	return 0;
}