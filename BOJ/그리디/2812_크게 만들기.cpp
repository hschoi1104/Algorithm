#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n, k, cnt;
string s;
deque<int>dq;
int main() {
	FIO;
	cin >> n >> k >> s;
	cnt = k;
	for (int i = 0; i < s.length(); i++) {
		if (!cnt) {
			dq.push_back(s[i] - '0');
		}
		else {
			if (!dq.size()) dq.push_back(s[i] - '0');
			else {
				while (!dq.empty() && cnt && dq.back() < s[i] - '0') {
					cnt--;
					dq.pop_back();
				}
				dq.push_back(s[i] - '0');
			}
		}
	}
	int tmp = 0;
	for (auto it : dq) {
		if (tmp == n - k) break;
		tmp += 1;
		cout << it;
	}
	return 0;
}