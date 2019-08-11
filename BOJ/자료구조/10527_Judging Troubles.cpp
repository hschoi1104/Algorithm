#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
map<string, int>m1;
map<string, int>m2;
int main() {
	int n;
	scanf("%d", &n);
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		m1[s]++;
	}
	for (int i = 0; i < n; i++) {
		cin >> s;
		m2[s]++;
	}
	int ans = 0;
	for (auto it = m1.begin(); it != m1.end(); it++) {
		ans += min(it->second, m2[it->first]);
	}
	printf("%d\n", ans);
	return 0;
}