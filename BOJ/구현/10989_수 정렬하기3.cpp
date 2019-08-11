#include <stdio.h>
using namespace std;
int chk[10001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		chk[x] += 1;
	}
	for (int i = 0; i <= 10000; i++) {
		if (chk[i] != 0) {
			for (int j = 0; j < chk[i]; j++) printf("%d\n", i);
		}
	}
	return 0;
}