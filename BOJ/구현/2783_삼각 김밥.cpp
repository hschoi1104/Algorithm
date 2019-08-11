#include <stdio.h>
#include <algorithm>
using namespace std;
double x, y, a, b,ans=0.0;
int n;
int main() {
	scanf("%lf %lf", &x, &y);
	ans = (1000.0 / y)*x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &a, &b);
		ans = min(ans, (1000.0 / b * a));
	}
	printf("%.2lf", ans);
	return 0;
}