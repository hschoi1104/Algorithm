#include <iostream>
#include <string>
using namespace std;
int main() {
	string s; cin >> s;
	bool flag = true;
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length() - i - 1]) flag = false;
	}
	if (flag == false) cout << s.length();
	else {
		int k = s[0];
		bool flag2 = true;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != k)  flag2 = false;
		}
		if (flag2 == true) cout << -1;
		else cout << s.length() - 1;
	}
	return 0;
}