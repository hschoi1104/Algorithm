#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <map>
using namespace std;
map <char, int> m;
vector<int>v;

int chk[100];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int num = 1;
		for (int i = s.length() - 1; i >= 0; i--) {
			m[s[i]] += num;
			num *= 10;
		}
	}
	int ans = 0;
	int val = 9;
	for (auto it = m.begin(); it != m.end(); it++) {
		v.push_back(it->second);
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < v.size(); i++) {
		ans += v[i] * val--;
	}
	printf("%d\n", ans);
}