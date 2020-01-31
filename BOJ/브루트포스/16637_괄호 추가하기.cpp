#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;
int ans = INT_MIN, n;
string s;
int cal(int a, int b, char op) {
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
}
void go(int idx, int res) {
	if (idx >= n) {
		ans = max(ans, res);
		return;
	}
	if (!idx)go(idx + 2, cal(res, s[idx] - '0', '+'));
	else go(idx + 2, cal(res, s[idx] - '0', s[idx - 1]));
	if (idx + 2 < n) {
		if (idx)go(idx + 4, cal(res, cal(s[idx] - '0', s[idx + 2] - '0', s[idx + 1]), s[idx - 1]));
		else go(idx + 4, cal(res, cal(s[idx] - '0', s[idx + 2] - '0', s[idx + 1]), '+'));
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	go(0, 0);
	cout << ans;
	return 0;
}