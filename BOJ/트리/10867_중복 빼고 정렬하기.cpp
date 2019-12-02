#include <iostream>
#include <set>
using namespace std;
set<int>s;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0,x; i < n; i++) {
		cin >> x; s.insert(x);
	}
	for (auto it : s) cout << it << " ";
	return 0;
}