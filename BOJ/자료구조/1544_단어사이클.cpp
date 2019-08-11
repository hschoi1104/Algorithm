#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, bool>m;
int cnt = 0;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s, str;
		cin >> s;
		str += s + s;
		if (m[s] != true) {
			m[s] = true;
			cnt++;
			for (int j = 0; j < s.length(); j++) {
				string temp = str.substr(0 + j, s.length());
				m[temp] = true;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}