#include <iostream>
#include <string>
using namespace std;

bool chk(char ch) {
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return false;
	return true;
}
int main() {
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		string s; cin >> s;
		cout << "#" << tt << " ";
		for (auto it : s) if (chk(it)) cout << it;
		cout << "\n";
	}
	return 0;
}