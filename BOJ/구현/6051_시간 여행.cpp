#include <stdio.h>
using namespace std;
int ans[1000001];//Äõ¸®¹øÈ£
int val[1000001];//Äõ¸®°ª
int main() {
	int n;
	scanf("%d", &n);
	ans[0] = -1;
	val[0] = -1;
	for (int i = 1; i <= n; i++) {
		char c;
		scanf(" %c", &c);
		if (c == 'a') {
			int x;
			scanf("%d", &x);
			ans[i] = i - 1;
			val[i] = x;
		}
		else if (c == 's') {
			ans[i] = ans[ans[i - 1]];
			val[i] = val[ans[i - 1]];
		}
		else if (c == 't') {
			int x;
			scanf("%d", &x);
			ans[i] = ans[x - 1];
			val[i] = val[x - 1];
		}
		printf("%d\n", val[i]);
	}
	return 0;
}