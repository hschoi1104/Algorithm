#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
vector<int>v;
int main() {
	int n, sum = 0;
	bool flag = false;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] - '0' == 0) flag = true;
		sum += s[i] - '0';
		v.push_back(s[i] - '0');
	}
	if (flag == true && sum % 3 == 0) {
		sort(v.begin(), v.end(), greater<int>());
		for (auto it : v)
			printf("%d", it);
	}
	else printf("-1");
	return 0;
}