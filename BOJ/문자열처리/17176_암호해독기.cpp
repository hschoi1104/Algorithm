#include <iostream>
#include <string>
#define FIO ios_base::sync_with_stdio(0), cin.tie(), cout.tie();
using namespace std;
int chk[55];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; chk[x] += 1;
	}
	string s;
	getline(cin, s);
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		if (s[i] == ' ') chk[0]--;
		else if ('a' <= s[i] && s[i] <= 'z') chk[s[i] - 97+27] -= 1;
		else if ('A' <= s[i] && s[i] <= 'Z') chk[s[i] - 64] -= 1;
	}

	for (int i = 0; i <= 52; i++) {
		if (chk[i] != 0) {
			cout << "n";
			return 0;
		}
	}
	cout << "y";
	return 0;
}