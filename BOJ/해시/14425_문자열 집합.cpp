#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
unordered_set<string>us;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, ans = 0;
	string s, t;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		us.insert(s);
	}
	for (int i = 0; i < m; i++) {
		cin >> t;
		if (us.find(t) != us.end()) ans += 1;
	}
	cout << ans;
	return 0;
}