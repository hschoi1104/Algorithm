#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;
int n, m;
deque<char> s;
char pi;
vector<deque<char>>v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	v.resize(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> pi, s.push_back(pi);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> pi;
			v[i].push_back(pi);
		}
	}
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		bool chk = false;
		deque<char>obj;
		for (auto it : v[i]) obj.push_back(it);

		for (int j = 0; j < v[i].size(); j++) {
			if (obj == s) {
				chk = true;
				ans.push_back(i);
				break;
			}
			obj.push_back(obj.front());
			obj.pop_front();
		}

		if (chk == false) {
			obj.clear();
			for (int j = v[i].size() - 1; j >= 0; j--) {
				if(v[i][j] == '1') obj.push_back('3');
				if (v[i][j] == '2') obj.push_back('4');
				if (v[i][j] == '3') obj.push_back('1');
				if (v[i][j] == '4') obj.push_back('2');
			}
			for (int j = 0; j < v[i].size(); j++) {
				if (obj == s) {
					chk = true;
					ans.push_back(i);
					break;
				}
				obj.push_front(obj.back());
				obj.pop_back();
			}
		}
	}
	cout << ans.size() << "\n";
	for (auto it : ans) {
		for (auto at : v[it]) cout << at << " ";
		cout << "\n";
	}
	return 0;
}