#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		string s = ' ';
		string a; cin >> a;
		a += 'R';
		char prev ='L'
		int dist = 0;
		int tmp = 0;
		for (int i = 0; i < s.length(); i++) {
			if (prev == 'L') {
				tmp += 1;
				dist = max(dist, tmp);
			}
			else if (prev == 'R') {
				dist = max(dist, tmp);
				tmp = 0;
			}
			prev = s[
		}
	}
	return 0;
}