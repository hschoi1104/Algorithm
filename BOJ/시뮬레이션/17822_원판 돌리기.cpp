#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
struct node {
	int x, d, k;
};
struct pos {
	int y, x;
};
vector<deque<int>>v;
vector<node>query;
queue<pos>q;
int n, m, t, val, dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }, bfs_chk[51][51], ans;
bool isadj = false;

void input() {
	cin >> n >> m >> t;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> val;
			v[i].push_back(val);
		}
	}
	for (int i = 0; i < t; i++) {
		node tmp; cin >> tmp.x >> tmp.d >> tmp.k;
		query.push_back(tmp);
	}
	return;
}
void update(int y, int x, int target) {
	memset(bfs_chk, 0, sizeof(bfs_chk));
	q.push(pos{ y,x });
	bfs_chk[y][x] = 1;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = cur.y + dir[k][0], nx = cur.x + dir[k][1];
			if (bfs_chk[ny][nx]) continue;
			//상하로 뚫는다면 넘어감
			if (0 > ny || ny >= n) continue;
			//좌우로 뚫는다면 처리해줌
			if (0 > nx || nx >= m) nx = (nx + m) % m;
			//같은경우 push
			if (v[ny][nx] == target) {
				isadj = true;
				q.push({ ny,nx });
				bfs_chk[ny][nx] = 1;
			}
		}
		v[cur.y][cur.x] = INT_MIN;
	}
	return;
}
int solve() {
	//query 순회
	for (auto cur_query : query) {
		//모든 회전판 순회 및 조작
		for (int i = 0; i < n; i++) {
			//조작해야하는 회전판
			if (!((i + 1) % cur_query.x)) {
				//시계방향으로 k번회전
				int cnt = cur_query.k;
				if (!cur_query.d) {
					while (cnt--) {
						v[i].push_front(v[i].back());
						v[i].pop_back();
					}
				}
				//반시계
				else {
					while (cnt--) {
						v[i].push_back(v[i].front());
						v[i].pop_front();
					}
				}
			}
		}
		//인접한 부분 찾기
		isadj = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] == INT_MIN) continue;
				//4방향 확인 같은 수가 있을때만 update함수 실행
				bool chk = false;
				for (int k = 0; k < 4; k++) {
					int ny = i + dir[k][0], nx = j + dir[k][1];
					//상하로 뚫는다면 넘어감
					if (0 > ny || ny >= n) continue;
					//좌우로 뚫는다면 처리해줌
					if (0 > nx || nx >= m) nx = (nx + m) % m;
					if (v[ny][nx] == v[i][j]) isadj = chk = true;
				}
				if (chk) update(i, j, v[i][j]);
			}
		}

		//인접한게 없었다면 평균구해서 -1,+1
		int sum = 0, cnt = 0;
		double avg = 0.0;
		if (!isadj) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (v[i][j] != INT_MIN) {
						sum += v[i][j];
						cnt += 1;
					}
				}
			}
			avg = (double)sum / (double)cnt;
			//평균보다 크면 -1 작으면 +1
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (v[i][j] == INT_MIN) continue;
					if ((double)v[i][j] > avg) v[i][j] -= 1;
					else if ((double)v[i][j] < avg) v[i][j] += 1;
				}
			}
		}
	}
	//모든 쿼리 순회 후 원판의 적힌 수의 합
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (v[i][j] != INT_MIN) ans += v[i][j];
	return ans;
}

int main() {
	FIO;
	input();
	cout << solve();
	return 0;
}