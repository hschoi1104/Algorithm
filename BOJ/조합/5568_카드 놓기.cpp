#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
vector<string>v;
string x;
int n, k;
set<int>s;
int chk[11];
void go(int cnt, string temp) {
	if (cnt == k) {
		s.insert(stoi(temp));
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (chk[i] == 1)continue;
		chk[i] = 1;
		go(cnt + 1, temp + v[i]);
		chk[i] = 0;
	}
	return;
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	go(0, "");
	cout << s.size();
	return 0;
}