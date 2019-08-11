#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n, x, y, ans = 0;
	string s;
	cin >> n >> x >> y;
	cin >> s;
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.length(); i++) {
		if (i < y) {
			if (s[i] != '0') ans += 1;
		}
		else if (i == y) {
			if (s[i] != '1')ans += 1;
		}
		else if (i > y && i < x) {
			if (s[i] != '0') ans += 1;
		}
		else break;
	}
	cout << ans;
	return 0;
}