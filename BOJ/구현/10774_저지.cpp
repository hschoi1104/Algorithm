#include <stdio.h>
#include <vector>
using namespace std;
vector<int>v;
vector<int>chk;
int ctoi(char c) {
	if (c == 'S') return 0;
	else if (c == 'M') return 1;
	else return 2;
}
int main() {
	int j, a, x, ans = 0;
	char c;
	scanf("%d %d", &j, &a);
	v.resize(j + 2);
	chk.resize(j + 2);
	for (int i = 1; i <= j; i++) {
		scanf(" %c", &c);
		v[i] = ctoi(c);
	}
	for (int i = 0; i < a; i++) {
		scanf(" %c %d", &c, &x);
		int size = ctoi(c);
		if (chk[x] == 0 && v[x] >= size) {
			ans += 1;
			chk[x] = 1;
		}
	}
	printf("%d", ans);
	return 0;
}