#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	int a, b, x, y; cin >> a >> b >> x >> y;
	if (a > b) swap(a, b);
	if (x > y) swap(x, y);
	cout << min(b - a, abs(x - a) + abs(y - b));
	return 0;
}