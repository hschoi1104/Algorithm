#include <iostream>
#include <vector>
using namespace std;
vector<int>seg;
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
//�����ִ� �ڸ��� �ε��� ���� ��ȯ
int go(int nodeNum, int val) {//�����ε���,ã�°�
	 //Ż������
	if (nodeNum >= h) return nodeNum;

	if (seg[nodeNum * 2] >= val) go(nodeNum * 2, val);
	else if (seg[nodeNum * 2] < val) go(nodeNum * 2 + 1, val - seg[nodeNum * 2]);
}
int main() {
	int N;
	scanf("%d", &N);
	while (N > h)h <<= 1;
	seg.resize(h * 2);
	//�ʱ�ȭ
	for (int i = 1; i <= N; i++) {
		update(i, 1);
	}
	for (int i = 1; i <= N; i++) {
		int x;
		scanf("%d", &x);
		int res = go(1, x)-h+1;
		if (x == 0) {
			while (1) {
				if (ans[res] != 0) res++;
				else {
					ans[res] = i;
					update(res, 0);
					break;
				}
			}
		}
		else {
			while (1) {
				if (ans[res + 1] != 0) res++;
				else {
					ans[res + 1] = i;
					update(res + 1, 0);
					break;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%d\n", ans[i + 1]);
	}
	return 0;
}