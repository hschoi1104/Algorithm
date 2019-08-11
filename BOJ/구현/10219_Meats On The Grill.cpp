#include <iostream>
#include <string>
using namespace std;
int n, m, t;
int main() {
	cin >> t;
	while (t--) {
		string s[12];
		cin >> n >> m;
		for (int i = 0; i < n; i++)	cin >> s[i];
		for (int i = n - 1; i >= 0; i--) cout << s[i] << "\n";
	}
	return 0;
}