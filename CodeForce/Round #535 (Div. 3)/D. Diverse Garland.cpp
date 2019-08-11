#include <iostream>
#include <string>
#include <limits.h>
using namespace std;
int main() {
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 1; i < s.length(); i++) {
		if (s[i - 1] != s[i]) continue;
		int chk[3] = { 0,0,0 };
		for (int j = i - 1; j <= i + 1; j++) {
			if (s[j] == 'R') chk[0]++;
			else if (s[j] == 'G') chk[1]++;
			else chk[2]++;
		}
		for (int j = 0; j < 3; j++) {
			if (chk[j] == 0) {
				if (j == 0) s[i] = 'R';
				else if (j == 1) s[i] = 'G';
				else s[i] = 'B';
				break;
			}
		}
		ans++;
	}
	cout << ans << "\n" << s;

	return 0;
}