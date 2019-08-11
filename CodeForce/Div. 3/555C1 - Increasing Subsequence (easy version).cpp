#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main() {
	int n, x; cin >> n;
	string ans = "";
	deque<int> q;
	for (int i = 0; i < n; i++) {
		cin >> x;
		q.push_back(x);
	}
	int prev = 0;
	while (!q.empty()) {
		if (q.size() == 1) {
			if (q.front() > prev) {
				ans += "L";
				q.pop_front();
			}
			break;
		}
		if (q.front() < q.back()) {
			if (q.front() > prev) {
				prev = q.front();
				ans += 'L';
				q.pop_front();
			}
			else {
				if (q.back() > prev) {
					prev = q.back();
					ans += 'R';
					q.pop_back();
				}
				else break;
			}
		}
		else if (q.front() > q.back()) {
			if (q.back() > prev) {
				prev = q.back();
				ans += 'R';
				q.pop_back();
			}
			else {
				if (q.front() > prev) {
					prev = q.front();
					ans += 'L';
					q.pop_front();
				}
				else break;
			}
		}
	}
	cout << ans.length() << "\n" << ans;
	return 0;
}