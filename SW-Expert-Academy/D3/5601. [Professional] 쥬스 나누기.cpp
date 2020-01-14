#include <iostream>
using namespace std;
int main() {
	int tt; cin >> tt;
	for (int t = 1; t <= tt; t++) {
		int n; cin >> n;
		cout << "#" << t << " ";
		for (int i = 0; i < n; i++) {
			cout << "1/" << n << " ";
		}
		cout << "\n";
	}
	return 0;
}