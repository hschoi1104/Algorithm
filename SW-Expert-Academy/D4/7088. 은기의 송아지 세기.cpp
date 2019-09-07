#include <iostream>
#include <string.h>
using namespace std;
int arr[100002][3];
void init() {
	memset(arr, 0, sizeof(arr));
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		init();
		int n, q; cin >> n >> q;
		for (int i = 1; i <= n; i++) {
			int p; cin >> p;
			arr[i][p - 1] = 1;
		}
		for (int i = 1; i <= n; i++) {
			for (int k = 0; k < 3; k++) arr[i][k] = arr[i][k] + arr[i - 1][k];
		}
		cout << "#" << tt << "\n";
		for (int i = 0; i < q; i++) {
			int a, b; cin >> a >> b;
			for (int k = 0; k < 3; k++) cout << arr[b][k] - arr[a - 1][k] << " ";
			cout << "\n";
		}
	}
	return 0;
}