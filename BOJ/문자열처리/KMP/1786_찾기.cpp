#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	//makeTable
	string s, f;
	getline(cin, f);
	getline(cin, s);
	vector<int>v(s.length(), 0);
	vector<int>ans;
	int j = 0;
	for (int i = 1; i < s.length(); i++) {
		while (j > 0 && s[i] != s[j]) {
			j = v[j - 1];
		}
		if (s[i] == s[j]) {
			v[i] = j+1;
			j += 1;
		}
	}
	
	//kmp

	j = 0;
	int cnt = 0;
	for (int i = 0; i < f.length(); i++) {
		while (j > 0 && f[i] != s[j]) {
			j = v[j - 1];
		}
		if (f[i] == s[j]) {
			if (j == s.length() - 1) {
				cnt++;
				ans.push_back(i - s.length() + 2);
				j = v[j];
			}
			else {
				j++;
			}
		}
	}
	cout << cnt << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}