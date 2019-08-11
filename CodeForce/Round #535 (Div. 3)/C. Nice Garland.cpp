#include <iostream>
#include <string>
#include <limits.h>
using namespace std;
string c[9] = { "RGB","RBG","GRB","GBR","BGR","BRG" };
int main() {
	int n;
	string s;
	cin >> n >> s;
	int ans=INT_MAX;
	int pattern = 0;
	for (int k = 0; k < 6; k++) {
		int cnt = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != c[k][i % 3]) cnt += 1;
		}
		if (ans > cnt) {
			ans = cnt;
			pattern = k;
		}
	}
	printf("%d\n", ans);
	for (int i = 0; i < n; i++) {
		cout << c[pattern][i % 3];
	}
	return 0;
}