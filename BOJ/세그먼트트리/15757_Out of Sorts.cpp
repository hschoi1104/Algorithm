#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int>p;
p arr[100001];
vector<int>seg;
int h = 1;
void update(int i, int val) {
	i += h - 1;
	seg[i] = val;
	while (i > 1) {
		i /= 2;
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}
	return;
}
int query(int L, int R, int idx, int nodeL, int nodeR) {
	if (R < nodeL || nodeR < L) return 0;
	else if (L <= nodeL && nodeR <= R) return seg[idx];
	int mid = (nodeL + nodeR) / 2;
	return query(L, R, idx * 2, nodeL, mid) + query(L, R, idx * 2 + 1, mid + 1, nodeR);
}
int main() {
	int n, x;
	scanf("%d", &n);
	while (h < n)h <<= 1;
	seg.resize(h * 2 + 1);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		arr[i] = { x,i+1 };
	}
	sort(arr, arr + n);
	int ans = 1;
	for (int i = 0; i < n - 1; i++) {
		update(arr[i].second, 1);
		ans = max(ans, i + 1 - query(1, i + 1, 1, 1, h));
	}
	printf("%d\n", ans);
	return 0;
}