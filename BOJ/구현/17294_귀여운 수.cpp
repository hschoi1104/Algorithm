#include <iostream>
#include <string>
using namespace std;
int main() {
	string s; cin >> s;
	int p = s[0] - s[1];
	for (int i = 1; i < s.length()-1; i++) {
		if (s[i] - s[i + 1] == p) continue;
		else {
			cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
			return 0;
		}
	}
	cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
	return 0;
}