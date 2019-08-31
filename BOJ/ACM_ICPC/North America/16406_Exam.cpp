#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string a, b; cin >> a >> b;
	int ctemp = 0, wtemp = 0;

	for (int i = 0; i < a.length(); i++) if (a[i] == b[i]) ctemp += 1;
	wtemp = a.length() - ctemp;
	int ans = 0;

	if (n <= ctemp) {
		ans += n;
		ans += wtemp;
	}
	else if (n > ctemp) {
		ans += ctemp;
		if (wtemp >= n - ctemp)
			ans += wtemp - (n - ctemp);
	}
	cout << ans;
	return 0;
}