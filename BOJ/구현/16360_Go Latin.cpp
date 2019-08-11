#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s[s.length() - 1] == 'a') {
			s += 's';
		}
		else if (s[s.length() - 1] == 'i' || s[s.length() - 1] == 'y') {
			s[s.length() - 1] = 'i';
			s += "os";
		}
		else if (s[s.length() - 1] == 'l') {
			s += "es";
		}
		else if (s[s.length() - 1] == 'e' && s[s.length() - 2] == 'n') {
			s[s.length() - 2] = 'a';
			s[s.length() - 1] = 'n';
			s += "es";
		}
		else if (s[s.length() - 1] == 'n') {
			s[s.length() - 1] = 'a';
			s += "nes";
		}
		else if (s[s.length() - 1] == 'o') {
			s += 's';
		}
		else if (s[s.length() - 1] == 'r') {
			s += "es";
		}
		else if (s[s.length() - 1] == 't') {
			s += "as";
		}
		else if (s[s.length() - 1] == 'u') {
			s += "s";
		}
		else if (s[s.length() - 1] == 'v') {
			s += "es";
		}
		else if (s[s.length() - 1] == 'w') {
			s += "as";
		}
		else {
			s += "us";
		}
		cout << s << "\n";
	}
	return 0;
}