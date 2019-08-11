#include <stdio.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < m; i++) {
		sum += n;
		if (sum%m == 0) continue;
		else cnt++;
	}
	printf("%d", cnt);
	return 0;
}