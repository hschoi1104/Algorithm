#include <stdio.h>
int main() {
	int t; scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		char ch[11];
		int size = 0;
		scanf("%s", ch);
		for (int i = 0; i < 11; i++) {
			if (ch[i] == '\0') break;
			size++;
		}
		bool flag = 1;
		for (int i = 0; i < size; i++) {
			if (size - i - 1 < i) break;
			if (ch[i] != ch[size - i - 1]) flag = false; break;
		}
		printf("#%d %d\n", tt, (flag) ? 1 : 0);
	}
	return 0;
}