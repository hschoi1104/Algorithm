#include <iostream>
#include <string>
using namespace std;
bool chk(string s) {
	if (s.length() % 2 == 0) {
		for (int i = 0; i < s.length() / 2; i++) {
			if (s[i] != s[s.length() - 1 - i]) return false;
		}
	}
	else {
		for (int i = 0; i < (s.length() - 1) / 2; i++) {
			if (s[i] != s[s.length() - 1 - i]) return false;
		}
	}
	return true;
}
int main() {
	string s;
	long long k;
	cin >> s >> k;
	if (chk(s)) printf("YES\n");
	else printf("NO\n");
	return 0;
}