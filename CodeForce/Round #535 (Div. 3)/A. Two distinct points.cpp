#include <stdio.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a == d) printf("%d %d\n", a, c);
		else printf("%d %d\n", a, d);
	}
	return 0;
}