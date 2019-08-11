#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string mix(string s, int len) {
	string res = "";
	if (len % 2 == 0) {
		for (int i = 0; i < len / 2; i++) {
			res += s[i];
			res += s[len - i - 1];
		}
	}
	else {
		for (int i = 0; i < len / 2 + 1; i++) {
			res += s[i];
			if (i == len / 2)continue;
			res += s[len - i - 1];
		}
	}
	return res;
}
int main() {
	int n, cnt = 0;
	string s, temp, res;
	cin >> n; cin >> s;
	temp = s;
	while (1) {
		res = mix(temp, temp.length());
		cnt++;
		if (res == s) break;
		temp = res;
	}
	n %= cnt;
	n = abs(cnt - n);

	temp = s;
	for (int i = 0; i < n; i++) {
		res = mix(temp, temp.length());
		temp = res;
	}
	cout << res;
	return 0;
}