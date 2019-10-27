#include <stdio.h>
int main() {
	int n; scanf("%d", &n);
	for (int t = 1; t <= n; t++) {
		char ch[62];
		scanf(" %[^\n]", &ch);
		printf("#%d ", t);
		int cnt = 0;
		for (int i = 0; i < 61; i++) {
			if (cnt == 3) break;
			if (i == 0) { printf("%c", ch[i] - 32); cnt++;}
			else if (ch[i] == ' ') { printf("%c", ch[i + 1] - 32); cnt++;}
		}
		printf("\n");
	}
	return 0;
}