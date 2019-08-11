#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int str1[150];
int str2[150];
int main() {
	string s1;
	cin >> s1;
	for (int i = 0; i < s1.length(); i++) {
		str1[s1[i]]++;
	}
	string s2;
	cin >> s2;
	for (int i = 0; i < s2.length(); i++) {
		str2[s2[i]]++;
	}
	int ans = 0;
	for (int i = 97; i < 123; i++) {
		if (str1[i] == str2[i]) continue;
		else ans += abs(str1[i] - str2[i]);
	}
	printf("%d", ans);
	return 0;
}