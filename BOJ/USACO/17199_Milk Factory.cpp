#include <iostream>
using namespace std;
int outdeg[101];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b, n; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		outdeg[a] += 1;
	}
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		if (outdeg[i] == 0 && ans != -1) {
			ans = -1;
			break;
		}
		else if (outdeg[i] == 0) ans = i;
	}
	cout << ans;
	return 0;
}