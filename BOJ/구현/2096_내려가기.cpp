#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int cur1 = 0, cur2 = 0, cur3 = 0;
	int cur4 = 0, cur5 = 0, cur6 = 0;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d",&a,&b,&c);
		int res1 = max(cur1 + a, cur2 + a);
		int res2 = max(cur1 + b, max(cur2 + b, cur3 + b));
		int res3 = max(cur2 + c, cur3 + c);
		int res4 = min(cur4 + a, cur5 + a);
		int res5 = min(cur4 + b, min(cur5 + b, cur6 + b));
		int res6 = min(cur5 + c, cur6 + c);
		cur1 = res1;
		cur2 = res2;
		cur3 = res3;
		cur4 = res4;
		cur5 = res5;
		cur6 = res6;
	}
	printf("%d %d", max(cur1, max(cur2, cur3)),min(cur4,min(cur5,cur6)));
}