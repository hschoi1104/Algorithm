#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;
int dir[2][2] = { {0,1},{1,0} };
typedef struct node {
	int y;
	int x;
	char p;
	int res = 0;
};
int n;
char g[6][6];
queue<node>q;
int max_val = INT_MIN;
int min_val = INT_MAX;
int cal(char p, int num, int res) {
	if (p == '+') return res + num;
	else if (p == '-') return res - num;
	else if (p == '*') return res * num;
}
void bfs() {
	node s = { 0,0,'n',g[0][0] - '0' };
	q.push(s);
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		if (cur.y == n - 1 && cur.x == n - 1) {
			max_val = max(max_val, cur.res);
			min_val = min(min_val, cur.res);
			continue;
		}
		for (int k = 0; k < 2; k++) {
			int ny = cur.y + dir[k][0];
			int nx = cur.x + dir[k][1];
			if (0 <= ny && ny < n && 0 <= nx && nx < n) {
				if (cur.p == 'n') {
					node next = { ny,nx,g[ny][nx],cur.res };
					q.push(next);
				}
				else {
					node next = { ny,nx,'n',cal(cur.p,g[ny][nx] - '0',cur.res) };
					q.push(next);
				}
			}
		}
	}
	return;
}
int main() {
	cin >> n;

	for (int i = 0; i < n; i++)	for (int j = 0; j < n; j++) cin >> g[i][j];
	bfs();
	cout << max_val << " " << min_val;
	return 0;
}