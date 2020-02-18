#include <iostream>
using namespace std;

int main() {
	int d, k; cin >> d >> k;
	// A
	for (int i = 1; i < k; i++) {
		//B
		for (int j = i; j < k; j++) {
			int t = 3;
			int a = i, b = j, c = a + b;
			while (t < d) {
				t++;
				a = b;
				b = c;
				c = a + b;
			}
			if (c == k) {
				cout << i << "\n" << j;
				return 0;
			}
			if (a + b > k)break;
		}
	}
	return 0;
}