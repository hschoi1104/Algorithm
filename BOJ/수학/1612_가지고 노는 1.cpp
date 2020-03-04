#include <iostream>
using namespace std;
int main() {
	int n, ans = 1, tmp = 1; cin >> n;
	if (n % 2 == 0 || n % 5 == 0) {
		cout << "-1" << "\n";
		return 0;
	}
	while ((tmp % n) != 0) {
		ans += 1;
		tmp = (tmp % n) * 10 + 1;
	}
	cout << ans << "\n";
	return 0;
}