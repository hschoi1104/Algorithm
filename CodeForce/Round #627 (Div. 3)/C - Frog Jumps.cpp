#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		s += 'R';
		int pos = -1;
		int tmp = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'R') {
				tmp = max(tmp, i - pos);
				pos = i;
			}
		}
		tmp = max(tmp, int(s.length() - pos));
		cout << tmp << "\n";
	}
	return 0;
}