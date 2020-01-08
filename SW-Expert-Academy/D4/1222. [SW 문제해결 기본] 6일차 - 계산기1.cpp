#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tt = 10;
	for (int t = 1; t <= tt; t++) {
		int n,ans=0; cin >> n;
		string s; cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '+') continue;
			else ans += s[i]-'0';
		}
		cout << "#"<<t<<" "<<ans<<"\n";
	}
	return 0;
}