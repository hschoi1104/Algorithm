#include <iostream>
#include<string>
using namespace std;
string s;
int main() {
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 97 && s[i] <= 122) s[i] -= 32;
		cout << s[i];
	}
	return 0;
}