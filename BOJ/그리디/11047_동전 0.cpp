#include <stdio.h>
#include <vector>
using namespace std;

vector<int>coin;
int n, k, x, ans = 0;

int main() {

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		coin.push_back(x);
	}
	for (int i = coin.size() - 1; i >= 0; i--) {
		if (k == 0) break;
		if (coin[i] <= k) {
			ans += k / coin[i];
			k -= (coin[i] * (k / coin[i]));
		}
	}
	printf("%d", ans);
	return 0;
}