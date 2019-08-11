#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int ans = 0, a, b, n; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		arr[a] += 1;
		arr[b] += 1;
		ans = max(ans, max(arr[a], arr[b]));
	}
	cout << ans +1;
	return 0;
}