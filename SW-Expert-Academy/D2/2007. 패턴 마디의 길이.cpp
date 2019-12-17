#include <stdio.h>
using namespace std;
int main() {
	int x; scanf("%d", &x);
	for (int tt = 1; tt <= x; tt++) {
		char ch[31]; scanf("%s", ch);
		for (int i = 1; i <= 10; i++) {
			bool flag = 1;
			for (int j = 0; j < 30; j++) {
				if (ch[j] != ch[j % i]) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				printf("#%d %d\n",tt, i);
				break;
			}
		}
	}
	return 0;
}