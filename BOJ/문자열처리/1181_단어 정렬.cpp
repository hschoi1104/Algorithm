#include <iostream>
#include <set>
#include <string>
#define FIO ios_base::sync_with_stdio(0), cin.tie(), cout.tie();
using namespace std;
set<pair<int,string>>s;
int main() {
	int n; cin >> n;
	while (n--) {
		string x; cin >> x;
		s.insert({ x.length(),x });
	}
	for (auto it : s) {
		cout << it.second << "\n";
	}
	return 0;
}