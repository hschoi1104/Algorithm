#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
unordered_map<string, int>um;
set<string>se;
int cnt = 0;
int main() {
	string s;
	while (getline(cin, s)) {
		if (s == "") break;
		if (um.find(s) != um.end()) {
			um[s] += 1;
		}
		else {
			um.insert({ s,1 });
			se.insert(s);
		}
		cnt += 1;
	}
	for (auto it = se.begin(); it != se.end(); it++) {
		double percent = (double)um.find(*it)->second / (double)cnt;
		cout << *it << " ";
		printf("%.4lf\n", percent*100.0);
	}
	return 0;
}