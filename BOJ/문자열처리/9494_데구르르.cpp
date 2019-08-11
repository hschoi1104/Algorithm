#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main() {
	while (1) {
		int n;
		scanf("%d", &n);
		cin.ignore();
		if (n == 0)break;
		int hole = 0;
		string s;
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			if (hole >= s.length()-1) continue;
			for (int i = hole; i < s.length(); i++) {
				if (s[i] == ' ') {
					hole = i;
					break;
				}
				if (i == s.length() - 1) hole = s.length();
			}
		}
		printf("%d\n", hole + 1);
	}
	return 0;
}