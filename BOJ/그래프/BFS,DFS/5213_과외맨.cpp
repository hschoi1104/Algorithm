#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;
typedef pair<int, int> p;
stack<int>s;
int dirl[3][2] = { {-1,0},{0,-1},{1,0} };
int dirr[3][2] = { {-1,0},{0,1},{1,0} };
int arr[501][1002];
int num[501][1002];
int visited[501][1002];
int maxindex = 0;
p path[250001];//이전노드,경로수
int n;
void printpath(int node) {
	s.push(node);
	if (path[node].first == node) return;
	else printpath(path[node].first);
}
void bfs() {
	queue<p>q;
	q.push({ 0,0 });
	visited[0][0] = visited[0][1] = 1;
	while (!q.empty()) {
		p left = q.front();
		p right = { left.first,left.second + 1 };
		q.pop();
		for (int k = 0; k < 3; k++) {
			int ny = left.first + dirl[k][0];
			int nx = left.second + dirl[k][1];
			if (ny >= 0 && ny < n && nx >= 0 && nx < 2 * n) {//arr의 범위에 들어가는가?
				if (visited[ny][nx] == 0 && arr[ny][nx] != 0 && arr[ny][nx] == arr[left.first][left.second]) {
					//y축이 홀수 인경우 시작점은 둘다 홀수여야함
					if (ny % 2 == 1 && nx % 2 != 1)  nx -= 1;
					//y축이 짝수 인경우 시작점은 둘다 짝수여야함
					if (ny % 2 == 0 && nx % 2 != 0)   nx -= 1;

					q.push({ ny,nx });
					visited[ny][nx] = visited[ny][nx + 1] = 1;
					//경로추적을 위한 저장
					if (path[num[ny][nx]].second >= path[num[left.first][left.second]].second + 1)
						path[num[ny][nx]] = { num[left.first][left.second],  path[num[left.first][left.second]].second + 1 };
					maxindex = max(maxindex, num[ny][nx]);
				}
			}
		}

		for (int k = 0; k < 3; k++) {
			int ny = right.first + dirr[k][0];
			int nx = right.second + dirr[k][1];
			if (ny >= 0 && ny < n && nx >= 0 && nx < 2 * n) {//arr의 범위에 들어가는가?
				if (visited[ny][nx] == 0 && arr[ny][nx] != 0 && arr[ny][nx] == arr[right.first][right.second]) {
					//y축이 홀수 인경우 시작점은 둘다 홀수여야함
					if (ny % 2 == 1 && nx % 2 != 1)  nx -= 1;
					//y축이 짝수 인경우 시작점은 둘다 짝수여야함
					if (ny % 2 == 0 && nx % 2 != 0)   nx -= 1;

					q.push({ ny,nx });
					visited[ny][nx] = visited[ny][nx + 1] = 1;
					//경로역추적을 위한 저장
					if (path[num[ny][nx]].second >= path[num[right.first][right.second]].second + 1)
						path[num[ny][nx]] = { num[right.first][right.second], path[num[right.first][right.second]].second + 1 };
					maxindex = max(maxindex, num[ny][nx]);
				}
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		int a = 0, b = 0;
		if (i % 2 == 0)
			for (int j = 0; j < 2 * n; j += 2) {
				scanf("%d %d", &a, &b);
				arr[i][j] = a;
				arr[i][j + 1] = b;
				num[i][j] = num[i][j + 1] = cnt++;
			}
		else
			for (int j = 1; j < 2 * n - 1; j += 2) {
				scanf("%d %d", &a, &b);
				arr[i][j] = a;
				arr[i][j + 1] = b;
				num[i][j] = num[i][j + 1] = cnt++;
			}
	}
	for (int i = 0; i <= 250000; i++) {
		path[i] = { i,100000000 };
	}
	path[1] = { 1,1 };
	bfs();

	//제일 큰 타일 까지의 거리
	printf("%d\n", path[maxindex].second);
	//경로역추적
	printpath(maxindex);
	//저장된 경로 출력
	while (!s.empty()) {
		if (s.size() == 1) {
			printf("%d\n", s.top());
			break;
		}
		printf("%d ", s.top());
		s.pop();
	}
	return 0;
}