#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
	int n,val;
	bool prime = true;
	scanf("%d", &n);
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) {
			prime = false;
			val = i;
			break;
		}
	}
	if(prime == true) printf("%d", n-1);
	else {
		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0) {
				printf("%d", n - n / i);
				break;
			}
		}
	}
	return 0;
}