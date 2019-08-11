﻿#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a = "abcdefghijklmnopqrstuvwxyz";
int l[27];
int chk[27];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	string s;
	cin.ignore();
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		chk[s[i] - 97]++;
	}
	for (int i = 0; i < 26; i++) {
		if (chk[i] == 0)continue;
		string sub;
		for (int j = 0; j < k; j++) {
			sub += a[i];
		}
		for (int j = 0; j < s.length() - k + 1; j++) {
			if (sub[0] != s[j]) continue;
			string temp = s.substr(j, k);
			if (temp == sub) {
				j += k - 1;
				l[i]++;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		ans = max(ans, l[i]);
	}
	printf("%d", ans);
	return 0;
}