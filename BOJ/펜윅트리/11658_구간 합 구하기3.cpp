#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
vector<vector<ll>>t;
ll arr[1026][1026];
int n, m;
void update(int x, int y, ll val) {
	int i = x;
	while (i <= n) {
		int j = y;
		while (j <= n) {
			t[i][j] += val;
			j += j & (-j);
		}
		i += i & (-i);
	}
}
ll sum(int x, int y) {
	ll res = 0;
	int i = x;
	while (i > 0) {
		int j = y;
		while (j > 0) {
			res += t[i][j];
			j -= j & (-j);
		}
		i -= i & (-i);
	}
	return res;
}
int main() {

	scanf("%d %d", &n, &m);

	t.resize(n + 2);
	for (int i = 0; i < n + 2; i++) t[i].resize(n + 2);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
			update(i, j, arr[i][j]);
		}
	}
	for (int i = 0; i < m; i++) {
		int w;
		scanf("%d", &w);
		if (w == 0) {
			int x, y;
			ll c;
			scanf("%d %d %lld", &x, &y, &c);
			update(x, y, c-arr[x][y]);
			arr[x][y] = c;
		}
		else {
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			printf("%lld\n", sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1));
		}
	}
	return 0;
}