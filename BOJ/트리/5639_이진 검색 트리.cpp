#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;
int x;
vector<int>v;
void go(int l, int r) {
	int root = v[l];
	if (l == r) {
		printf("%d\n", root);
		return;
	}
	int lt = -1;
	int rt = r + 1;
	if (v[l + 1] < root)lt = l + 1;
	for (int i = l + 1; i <= r; i++) {
		if (v[i] > root) {
			rt = i;
			break;
		}
	}
	if (lt != -1) go(lt, rt - 1);
	if (rt < r + 1) go(rt, r);
	printf("%d\n", root);
	return;
}
int main() {
	while (~scanf("%d", &x)) {
		v.push_back(x);
	}
	go(0, v.size() - 1);
	return 0;
}