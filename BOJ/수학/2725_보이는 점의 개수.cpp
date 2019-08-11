#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
int cnt[1001];

int go(int a, int b) {
	if (b == 0) return a;
	return go(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int c; cin >> c;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (go(i, j) == 1)cnt[max(i, j)] += 1;
		}
	}
	for (int i = 1; i <= 1000; i++) cnt[i] += cnt[i - 1];

	while (c--) {
		int  n; cin >> n;
		cout << cnt[n] << "\n";
	}
	return 0;
}