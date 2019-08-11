#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
typedef pair<int, int> p;
int arr[101][101];
int chkair[101][101];
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int n, m,hours=0;

void bfs(int y, int x) {
	queue<p> q;
	q.push({ y,x });
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		chkair[cy][cx] = 1;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = cy + dir[k][0];
			int nx = cx + dir[k][1];
			if (0 <= ny && ny < n && 0 <= nx && nx < m) {
				//Ž���� ���⸦ �����ٸ� queue�� Ǫ��
				if (arr[ny][nx] == 0 && chkair[ny][nx] == 0) {
					chkair[ny][nx] = 1;
					q.push({ ny,nx });
				}
				//ġ� �����ٸ� ���̰� ������
				if (arr[ny][nx] == 1 && chkair[ny][nx] == 0) {
					chkair[ny][nx] = 1;
					arr[ny][nx] = 0;
				}
			}
		}
	}
	return;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) scanf("%d", &arr[i][j]);
	//ġ� �ٳ�� ������ ġ�� ������ ��ȯ
	int cheesecnt = 0;
	while (1) {
		for(int i=0;i<n;i++) memset(chkair[i], 0, sizeof(chkair[i]));
		int cnt = 0;
		//���̱� ���� ġ�� ������ ����
		for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) if (arr[i][j] == 1) cnt += 1;
		if (cnt == 0) {
			printf("%d\n%d", hours,cheesecnt);
			return 0;
		}
		else cheesecnt = cnt;
		//���̱� ����
		bfs(0, 0);
		hours += 1;
	}
	return 0;
}