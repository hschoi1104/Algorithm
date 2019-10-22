#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int>pi;
string pattern = "IOI", str;
int ans, m, n;
void fail()
{
	int j = 0;
	for (int i = 1; i < pattern.size(); i++)
	{
		while (j > 0 && pattern[i] != pattern[j]) j = pi[j - 1];
		if (pattern[i] == pattern[j])
		{
			pi[i] = j + 1;
			j++;
		}
	}
}
void kmp() {
	int j = 0;
	for (int i = 0; i < str.size(); i++) {
		while (j > 0 && pattern[j] != str[i]) j = pi[j - 1];
		if (str[i] == pattern[j]) {
			if (j == pattern.size() - 1) {
				j = pi[j];
				ans++;
			}
			else {
				j++;
			}
		}
	}
}
void getPattern(int n) {
	while (n--) pattern += "OI";
	return;
}
int main() {
	cin >> n >> m >> str;
	getPattern(n - 1);
	pi.resize(pattern.size());
	fail();
	kmp();
	cout << ans;
	return 0;
}
