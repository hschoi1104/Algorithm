#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int c = 0, d = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') c++;
		else if (s[i] == ')')d++;
	}
	if (c != d) {
		cout << -1;
		return 0;
	}
	int a = 0, b = 0, cnt = 0, prev = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == ')') {
			b += 1;
		}
		else {
			a += 1;
		}
		if (prev == -1 && a - b == 0) {
			cnt++;
		}
		if (a - b < 0) {
			prev = -1;
			cnt++;
		}
		else prev = 0;
	}
	cout << cnt;
	return 0;
}