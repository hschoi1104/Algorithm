#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

vector<int>seg;
int h = 1;
void update(int i, int val) {
	int pos = i + h;
	seg[pos] = val;
	while (pos > 1) {
		pos /= 2;
		seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
	}
}
int query(int L, int R, int node, int nodeL, int nodeR) {
	if (nodeL > R || nodeR < L) return 0;
	else if (L <= nodeL && nodeR <= R) return seg[node];
	int mid = (nodeL + nodeR) / 2;
	return query(L, R, node * 2, nodeL, mid) + query(L, R, node * 2 + 1, mid + 1, nodeR);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		seg.clear();
		int n, m;
		int index[100001];
		scanf("%d %d", &n, &m);
		//init
		h = 1;
		while (h < m + n + 1) h <<= 1;
		seg.resize(2 * h);
		memset(index, 0, sizeof(index));
		for (int i = 0; i < n; i++) {
			update(i + m, 1);
			index[i + 1] = i + m;
		}
		//query
		for (int i = 0; i < m; i++) {
			int x;
			scanf("%d", &x);
			if (i == 0)printf("%d", query(1, index[x], 1, 1, h));
			else printf(" %d", query(1, index[x], 1, 1, h));
			update(m - i - 1, 1);
			update(index[x], 0);
			index[x] = m - i - 1;
		}
		printf("\n");
	}
}