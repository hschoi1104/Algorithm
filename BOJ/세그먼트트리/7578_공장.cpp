#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<int> node;
vector<int> loc;
int arr1[500001];
int arr2[1000010];
int h = 1;
void update(int i, int val) {
	i += h - 1;
	node[i] += val;
	while (i > 1) {
		i /= 2;
		node[i] = node[i * 2] + node[i * 2 + 1];
	}
}
ll query(int L, int R, int nodeNum, int nodeL, int nodeR) {

	if (L <= nodeL && nodeR <= R) return node[nodeNum];
	else if (nodeR < L || R < nodeL) return 0;
	int mid = (nodeL + nodeR) / 2;
	return query(L, R, nodeNum * 2, nodeL, mid) + query(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}
int main(void) {
	int n;
	scanf("%d", &n);
	while (h < n) h <<= 1;
	node.resize(h * 2);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr1[i]);
	}
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		arr2[x] = i;
	}
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		update(arr2[arr1[i]], 1);
		sum += query(arr2[arr1[i]] + 1, n, 1, 1, h);
	}
	printf("%lld", sum);
}

