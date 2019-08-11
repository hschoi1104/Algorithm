#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
	long long s;
	scanf("%lld", &s);
	printf("%d", ((int)sqrt(8LL * s + 1) - 1) / 2);
	return 0;
}