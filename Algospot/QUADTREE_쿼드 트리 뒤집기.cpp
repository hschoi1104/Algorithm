#include <iostream>
#include <string>
using namespace std;
string go(string::iterator& it) {
	char head = *it;
	++it;
	if (head == 'w' || head == 'b') return string(1, head);
	string topleft = go(it);
	string topright = go(it);
	string bottomleft = go(it);
	string bottomright = go(it);
	return "x" + bottomleft + bottomright + topleft + topright;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int c; cin >> c;
	while (c--) {
		string s; cin >> s;
		string::iterator it = s.begin();
		cout << go(it)<<"\n";
	}
	return 0;
}