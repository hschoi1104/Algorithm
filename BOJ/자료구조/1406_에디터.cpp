#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;
list<char>li;
string s;
char op,t;
int n;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> n;
	for (auto it : s)li.push_back(it);
	auto cur = li.end();
	while (n--) {
		cin >> op;
		if (op == 'L') {
			if (cur != li.begin()) cur--;
		}
		else if (op == 'D') {
			if (cur != li.end())cur++;
		}
		else if (op == 'B') {
			if (cur != li.begin()) {
				cur--;
				cur = li.erase(cur);
			}
		}
		else if (op == 'P') {
			cin >> t;
			li.insert(cur, t);
		}
	}
	for (auto it : li)cout << it;
	return 0;
}