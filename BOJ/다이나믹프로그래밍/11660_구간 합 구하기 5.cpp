#include <iostream>
using namespace std;
typedef long long ll;
ll arr[1025][1025];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) arr[i][j] += arr[i][j - 1];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) arr[i][j] += arr[i - 1][j];

	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << arr[c][d] - arr[c][b-1] - arr[a -1][d] + arr[a - 1][b - 1]<<"\n";
	}
	return 0;
}