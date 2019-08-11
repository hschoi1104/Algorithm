#include <stdio.h>
#include <queue>
using namespace std;
queue<pair<int, int>> q;
int arr[10002];
int visited[10002];
int n, a, b;

int bfs(int s, int e) {
	q.push({ s,0 });
	visited[s] = 1;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		if (cur.first == e) return cur.second;
		//뒤로가는경우
		for (int i = cur.first; i > 0; i -= arr[cur.first]) {
			if (i == cur.first)continue;
			if (visited[i] != 1)q.push({ i,cur.second + 1 });
		}
		//앞으로가는경우
		for (int i = cur.first; i <= n; i += arr[cur.first]) {
			if (i == cur.first)continue;
			if (visited[i] != 1)q.push({ i,cur.second + 1 });
		}
	}
	return -1;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	scanf("%d %d", &a, &b);
	int res = 0;
	if (a == b) res = 1;
	else res = bfs(a, b);
	printf("%d\n", res);
	return 0;
}