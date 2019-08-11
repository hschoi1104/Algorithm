#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int>n;
vector<char>p;
int main() {
	string s,t;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		//숫자인경우
		if (s[i] != '+' && s[i] != '-') t += s[i];
		else {
			n.push_back(stoi(t));
			p.push_back(s[i]);
			t = "";
		}
	}
	n.push_back(stoi(t));
	int ans = n[0];
	bool flag = false;
	for (int i = 1; i < n.size(); i++) {
		if (p[i-1] == '+' && flag == false) {
			ans += n[i];
		}
		else {
			flag = true;
			ans -= n[i];
		}
	}
	
	printf("%d", ans);
	return 0;
}