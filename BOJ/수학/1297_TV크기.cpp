#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);
	double val = a/sqrt(b*b + c*c);
	printf("%d %d", (int)(b*val), (int)(c*val));
}
