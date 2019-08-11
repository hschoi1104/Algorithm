#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll>seg;
int h = 1;
void update(int i,ll val) {
	i += h-1;
	seg[i] = val;
	while (i > 1) {
		i /= 2;
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}
}
ll query(int L,int R,int nodeNum,int nodeL,int nodeR) {
	//L,R : 세그에서 찾으려는 값의 범위
	//nodeNum : 현재 보고있는노드
	//nodeR,L : 현재 보고있는 범위
	if (L <= nodeL && nodeR <= R) return seg[nodeNum];
	else if (nodeR < L || R < nodeL) return 0;
	int mid = (nodeL + nodeR) / 2;
	return query(L, R, nodeNum * 2, nodeL, mid) + query(L, R, nodeNum * 2 + 1, mid + 1,nodeR);
}
int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	while (N > h)h <<= 1;
	seg.resize(h*2);
	//초기화
	for (int i = 1; i <= N; i++) {
		ll x;
		scanf("%lld", &x);
		update(i, x);
	}
	for (int i = 0; i < M + K; i++) {
		int a, b;
		ll c;
		scanf("%d %d %lld", &a, &b, &c);
		if (a == 1) {
			update(b, c);
		}
		else {
			printf("%lld\n", query(b, c, 1, 1, h));
		}
	}
	return 0;
}