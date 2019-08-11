#include <iostream>
using namespace std;
int n, cnt, a;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		for (int j = 1; j <= 10; j++) {
			cin >> a;
			if (a == ((j - 1) % 5) + 1) cnt += 1;
		}
		if (cnt == 10) cout << i << "\n";
	}
	return 0;
}