#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
	FIO;
	string s; cin >> s;
	int prv = 0,cnt=0;
	for (int i = 0; i < s.length(); i++) {
		if (i == 0) prv = s[i];
		if (prv != s[i]) {
			cnt += 1;
			prv = s[i];
		}
	}
	cout << (cnt + 1)/2;
	return 0;
}