#include <stdio.h>
using namespace std;
int go(int n, int y, int x) {
	if (n == 0) return 0;
	//Ã¹±¸¿ª
	int half = (2 << (n-1)) / 2;
	if (half > y && half > x) {
		return go(n - 1, y, x);
	}
	else if (half > y && half <= x) {
		return go(n - 1, y, x - half) + half * half;
	}
	else if (half <= y && half > x) {
		return go(n - 1, y - half, x) + 2 * (half * half);
	}
	else if (half <= y && half <= x) {
		return go(n - 1, y - half, x - half) + 3 * (half * half);
	}
}
int main() {
	int n, r, c;
	scanf("%d %d %d", &n, &r, &c);
	printf("%d\n", go(n, r, c));
	return 0;
}