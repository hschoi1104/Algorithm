#include <stdio.h>
#include <string.h>
using namespace std;
int arr[100001];
int chk[100001];
int start[100001];
int dfs(int s, int c,int cnt) {
	//�������� �̹� �湮�� ���̶��
	if (chk[c]) {
		//�װ� �������� �ƴ϶�� ��ü ����Ŭ�� �ƴ�
		if (start[c] != s) return 0;
		//�߰��� ����Ŭ�� ���ԵȰ��
		return cnt - chk[c];
	}
	//��θ� ���鼭 ������ ���� ������ ��������
	//chk�� �ʱ�ȭ ���� �ʱ� ������ �������� ������ ���ϼ� ����
	start[c] = s;
	chk[c] = cnt;
	return dfs(s, arr[c], cnt + 1);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, ans = 0;
		scanf("%d", &n);
		memset(arr, 0, sizeof(arr));
		memset(chk, 0, sizeof(chk));
		memset(start, 0, sizeof(start));
		for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
		for (int i = 1; i <= n; i++) {
			//�ѹ��湮�� ���� �湮���� �ʾƵ��ȴ�.
			if (!chk[i]) {
				int res = dfs(i, i,1);
				ans += res;
			}
		}
		printf("%d\n", n - ans);
	}
	return 0;
}