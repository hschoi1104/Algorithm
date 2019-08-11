#include<stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<string> rule1(1001, "");
		vector<string> rule2(1001, "");
		vector<string> rule3(1001, "");
		vector<string> rule4(1001, "");
		vector<int>ans(1001, 0);
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			rule1[i] = (s);
		}
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < n; j++) {
				if (s == rule1[j]) {
					ans[i] = j;
					break;
				}
			}
			rule2[i] = (s);
		}
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			rule4[ans[i]] = s;
		}
		for (int i = 0; i < n; i++) {
			cout << rule4[i] << " ";
		}
		cout << "\n";
		rule1.clear();
		rule2.clear();
		rule3.clear();
		rule4.clear();
	}
	return 0;
}