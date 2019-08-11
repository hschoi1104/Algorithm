#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, t = "UCPC";
	int pos = 0;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (pos == 4) break;
		if (s[i] == t[pos]) pos++;
	}
	if (pos == 4) printf("I love UCPC");
	else printf("I hate UCPC");
}