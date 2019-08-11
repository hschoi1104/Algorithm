#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>v;
int n, x;
int ans[1000];
int chk[100];
void go(int c, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < cnt; i++)
			printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for (int i = c; i < n; i++) {
		if (chk[i] == 0) {
			ans[cnt] = v[i];
			chk[i] = 1;
			go(i + 1, cnt+1);
			chk[i] = 0;
		}
	}
	return;
}
int main() {
	while (1) {
		scanf("%d", &n);
		v.clear();
		if (n == 0)break;

		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			v.push_back(x);
		}
		//sort(v.begin(), v.end());
		go(0, 0);
		printf("\n");
	}
	return 0;
}