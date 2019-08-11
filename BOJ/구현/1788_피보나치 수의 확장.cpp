#include<stdio.h>
#include <math.h>
using namespace std;
int pdp[1000001];
int mdp[1000001];
int main() {
	int n;
	scanf("%d", &n);
	if (n >= 0) {
		pdp[0] = 0;
		pdp[1] = pdp[2] = 1;
		for (int i = 3; i <= 1000000; i++) pdp[i] = (pdp[i - 1] % 1000000000 + pdp[i - 2] % 1000000000) % 1000000000;
		if (pdp[n] == 0)printf("%d\n%d", 0, pdp[0]);
		else printf("%d\n%d", 1, pdp[n]);
	}
	else {
		mdp[0] = 0;
		mdp[1] = 1;
		mdp[2] = -1;
		n *= -1;
		for (int i = 3; i <= 1000000; i++) mdp[i] = (mdp[i - 2] % 1000000000 - mdp[i - 1] % 1000000000) % 1000000000;
		if (mdp[n] < 0) printf("%d\n%d", -1, abs(mdp[n]));
		else if (mdp[n] == 0)printf("%d\n%d", 0, mdp[n]);
		else printf("%d\n%d", 1, mdp[n]);
	}
	return 0;

}