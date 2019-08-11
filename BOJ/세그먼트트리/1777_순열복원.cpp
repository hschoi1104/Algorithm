#include <stdio.h>
#include <vector>
using namespace std;
vector<int>seg;
vector<int>arr;
int ans[100010];
int h = 1;
void update(int i, int val) {
	i += h - 1;
	seg[i] = val;
	while (i > 1) {
		i /= 2;
		seg[i] = seg[i * 2] + seg[i * 2 + 1];

	}
}
int go(int val, int nodeNum) {
	if (nodeNum >= h) return nodeNum;

	if (seg[nodeNum * 2 + 1] >= val && seg[nodeNum*2+1]>0) go(val, nodeNum * 2 + 1);
	else  go(val - seg[nodeNum * 2 + 1], nodeNum * 2);
	//if (seg[nodeNum * 2 + 1] < val)
}
int main() {
	int n;
	scanf("%d", &n);
	while (h < n)h <<= 1;
	//init
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) update(i, 1);
	//input
	arr.resize(n + 1);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	//go
	for (int i = n; i > 0; i--) {
		int res = go(arr[i-1], 1)-h+1;
		if (arr[i-1] == 0) {
			while (1) {
				if (ans[res] == 0) {
					ans[res] = i;
					update(res, 0);
					break;
				}
				res--;
			}
		}
		else {
			while (1) {
				if (ans[res-1] == 0) {
					ans[res-1] = i;
					update(res-1, 0);
					break;
				}
				res--;
			}
		}
	}
	//printf
	printf("%d", ans[1]);
	for (int i = 2; i <= n; i++) {
		printf(" %d", ans[i]);
	}
	return 0;
}