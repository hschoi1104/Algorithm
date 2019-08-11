#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int lcs[4010][4010];
int main() {
	int ans = 0;
	string a, b;
	cin >> a >> b;

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
			ans = max(ans, lcs[i][j]);
		}
	}
	cout << ans;

	return 0;
}