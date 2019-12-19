#include <stdio.h>
bool chk[11];
void init() {
	for (int i = 0; i < 10; i++) chk[i] = false;
}
bool check() {
	bool flag = true;
	for (int i = 0; i < 10; i++) {
		if (!chk[i]) flag = false;
	}
	return flag;
}
void write(int n) {
	while (n>0) {
		int tmp = n % 10;
		chk[tmp] = true;
		n -= tmp;
		n /= 10;
	}
}
int main() {
	int t; scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		init();
		int n; scanf("%d", &n);
		int cnt = 0;
		for (int i = n;; i += n) {
			cnt = i;
			write(i);
			if (check()) break;
		}
		printf("#%d %d\n", tt, cnt);
	}
	return 0;
}