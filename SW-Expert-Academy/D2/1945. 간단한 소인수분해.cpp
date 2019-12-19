#include <iostream>
using namespace std;
int ans[11];
int arr[5] = { 2,3,5,7,11 };
void init() {
	for (int i = 0; i < 5; i++) ans[arr[i]] = 0;
}
int main() {
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		init();
		int n; cin >> n;
		while (n != 1) {
			for (int i = 0; i < 5; i++) {
				if (n % arr[i] == 0) {
					ans[arr[i]] += 1;
					n /= arr[i];
					break;
				}
			}
		}
		cout << "#" << tt;;
		for (int i = 0; i < 5; i++) {
			cout <<" "<< ans[arr[i]];
		}
		cout << "\n";
	}
	return 0;
}