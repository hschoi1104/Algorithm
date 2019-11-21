#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
bool go() {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != s[s.length() - i - 1]) return false;
	}
	return true;
}
bool gogo(int left, int right, int cnt) {
	if (cnt >= 2) return false;
	if (left >= right) return true;
	else if (s[left] == s[right]) return gogo(left + 1, right - 1, cnt);
	else if (s[left] == s[right - 1] || s[left + 1] == s[right]) return max(gogo(left + 1, right, cnt + 1), gogo(left, right - 1, cnt + 1));
	else return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while (n--) {
		s.clear();
		cin >> s;
		if (go()) {
			cout <<"0\n";
			continue;
		}
		if (gogo(0, s.length() - 1, 0)) {
			cout <<"1\n";
			continue;
		}
		else cout <<"2\n";
	}
	return 0;
}