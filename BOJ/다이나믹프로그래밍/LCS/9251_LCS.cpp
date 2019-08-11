#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int lcs[1010][1010];
int main() {
	int ans = 0;
	string a, b;
	cin >> a >> b;
	a = "-" + a; b = "-" + b;
	if (a.size() > b.size())swap(a, b);
	for (int i = 1; i < b.length(); i++) {
		for (int j = 1; j < a.length(); j++) {
			if (a[j] == b[i]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			ans = max(ans, lcs[i][j]);
		}
	}
	cout << ans;
	return 0;
}