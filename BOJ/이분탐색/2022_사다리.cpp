#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int main() {
	double x, y, c;
	scanf("%lf %lf %lf", &x, &y, &c);
	double left = 0.0;
	double right = max(x, y);
	while (right - left > 0.000001) {
		double mid = (left + right) / 2.0;
		double lh = sqrt(x*x - mid * mid);
		double rh = sqrt(y*y - mid * mid);
		double midx = c * mid / rh;
		double res = (-lh) / mid * midx + lh;
		if (c < res) left = mid;
		else right = mid;
	}
	printf("%.3lf\n", left);
	return 0;
}