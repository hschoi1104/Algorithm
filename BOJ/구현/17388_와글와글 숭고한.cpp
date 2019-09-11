#include <iostream>
#include <algorithm>
using namespace std;
int max_val = 0;
int min_val = 999;
int main() {
	int a, b, c; cin >> a >> b >> c;
	int sum = a + b + c;
	min_val = min(min_val, min(a, min(b, c)));
	if (sum >= 100) cout << "OK";
	else {
		if (a == min_val) cout << "Soongsil";
		else if (b == min_val) cout << "Korea";
		else cout << "Hanyang";
	}
	return 0;
}