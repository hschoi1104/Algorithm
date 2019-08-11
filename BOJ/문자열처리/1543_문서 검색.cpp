#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, t;
	getline(cin, s);
	getline(cin, t);
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == t[0] && s.length() - i >= t.length()) {
			bool flag = true;
			for (int j = 0; j < t.length(); j++) {
				if (s[i + j] != t[j]) flag = false;
			}
			if (flag == true) {
				i += t.length() - 1;
				cnt++;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
