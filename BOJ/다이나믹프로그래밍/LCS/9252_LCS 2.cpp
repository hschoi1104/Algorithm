#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int lcs[1010][1010];
int main() {
	int ans = 0;
	string a, b;
	cin >> a >> b;

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			ans = max(ans, lcs[i][j]);
		}
	}

	string temp;
	int i = a.size();
	int j = b.size();

	while (i >= 1 && j >= 1) {
		if (lcs[i][j] == lcs[i - 1][j]) {
			i--;
		}
		else if (lcs[i][j] == lcs[i][j - 1]) {
			j--;
		}
		else {
			temp+=(a[i - 1]);
			i--; j--;
		}
	}
	reverse(temp.begin(), temp.end());
	cout << temp.size() << "\n";
	cout << temp;

	return 0;
}