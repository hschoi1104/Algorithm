#include <iostream>
using namespace std;
int a[101], o[101], t[101];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> o[i];
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= n; j++) t[j] = a[o[j]];
		for (int j = 1; j <= n; j++) a[j] = t[j];
	}
	for (int i = 1; i <= n; i++)cout << a[i] << "\n";
	return 0;
}