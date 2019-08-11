#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s, ans;
	int n, cnt = 0;
	cin >> n >> s;
	ans += s[0];
	for (int i = 1; i < s.length(); i++) {
		if (ans.length() % 2 == 0) ans += s[i];
		else {
			if (ans[ans.length() - 1] != s[i]) ans += s[i];
			else cnt += 1;
		}
	}
	if (ans.length() % 2 == 1) cnt += 1;
	cout << cnt << "\n";
	if (ans.length() == 1) cout << "";
	else {
		if (ans.length() % 2 == 0) cout << ans;
		else for (int i = 0; i < ans.length() - 1; i++) cout << ans[i];
	}
	return 0;
}