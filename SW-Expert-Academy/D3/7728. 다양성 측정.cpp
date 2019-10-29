#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
void go(int a, set<int>& se) {
	while (a > 0) {
		se.insert(a % 10);
		a /= 10;
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int t = 1; t <= n; t++) {
		set<int>s;
		int x; cin >> x;
		go(x, s);
		cout << "#" << t << " " << s.size() << "\n";
	}
	return 0;
}