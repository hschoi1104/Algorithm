#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int>v(200001);
string ans = "";
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> v[i];
	int l = 0, r = n - 1, prev = 0;
	while (l <= r) {
		if (l == r) {
			if (prev < v[l]) ans += 'L';
			break;
		}
		if (v[l] <= prev && v[r] <= prev) break;

		if (v[l] <= prev) {
			prev = v[r];
			ans += 'R';
			r -= 1;
		}
		else if (v[r] <= prev) {
			prev = v[l];
			ans += 'L';
			l += 1;
		}
		else if (v[l] > v[r]) {
			prev = v[r];
			ans += 'R';
			r -= 1;
		}
		else if (v[l] < v[r]) {
			prev = v[l];
			ans += 'L';
			l += 1;
		}
		else {
			string ls="L", rs="R";
			int lp = v[l], rp = v[r];
			for (int i = l+1; i <= r; i++) {
				if (v[i] > v[i - 1]) {
					ls += 'L';
					lp = v[i];
				}
				else break;
			}
			for (int i = r - 1; i >=l; i--) {
				if (v[i] > v[i + 1]) {
					rs += 'R';
					rp = v[i];
				}
				else break;
			}
			if (ls.length() > rs.length()) {
				ans += ls;
				prev = lp;
				l += ls.length();
			}
			else {
				ans += rs;
				prev = rp;
				r -= rs.length();
			}
		}
	}
	cout << ans.length() << "\n" << ans;
	return 0;
}