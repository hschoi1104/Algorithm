#include <iostream>
using namespace std;
int fac(int num) {
	if (num == 0) return 1;
	int res = 1;
	for (int i = num; i >= 1; i--) {
		res *= i;
	}
	return res;
}
int main() {
	int n, k; cin >> n >> k;
	cout << fac(n) / (fac(n - k) * fac(k));
	return 0;
}