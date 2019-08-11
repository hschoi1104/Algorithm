#include <iostream>
#include <string>
using namespace std;
int n, ans = 0;
string s;
int main() {
	cin >> n >> s;
	for (auto i : s) ans += (i - 64);
	cout << ans;
	return 0;
}