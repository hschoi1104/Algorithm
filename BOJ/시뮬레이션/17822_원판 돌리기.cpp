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
			//���Ϸ� �մ´ٸ� �Ѿ
			if (0 > ny || ny >= n) continue;
			//�¿�� �մ´ٸ� ó������
			if (0 > nx || nx >= m) nx = (nx + m) % m;
			//������� push
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
	//query ��ȸ
	for (auto cur_query : query) {
		//��� ȸ���� ��ȸ �� ����
		for (int i = 0; i < n; i++) {
			//�����ؾ��ϴ� ȸ����
			if (!((i + 1) % cur_query.x)) {
				//�ð�������� k��ȸ��
				int cnt = cur_query.k;
				if (!cur_query.d) {
					while (cnt--) {
						v[i].push_front(v[i].back());
						v[i].pop_back();
					}
				}
				//�ݽð�
				else {
					while (cnt--) {
						v[i].push_back(v[i].front());
						v[i].pop_front();
					}
				}
			}
		}
		//������ �κ� ã��
		isadj = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] == INT_MIN) continue;
				//4���� Ȯ�� ���� ���� �������� update�Լ� ����
				bool chk = false;
				for (int k = 0; k < 4; k++) {
					int ny = i + dir[k][0], nx = j + dir[k][1];
					//���Ϸ� �մ´ٸ� �Ѿ
					if (0 > ny || ny >= n) continue;
					//�¿�� �մ´ٸ� ó������
					if (0 > nx || nx >= m) nx = (nx + m) % m;
					if (v[ny][nx] == v[i][j]) isadj = chk = true;
				}
				if (chk) update(i, j, v[i][j]);
			}
		}

		//�����Ѱ� �����ٸ� ��ձ��ؼ� -1,+1
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
			//��պ��� ũ�� -1 ������ +1
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (v[i][j] == INT_MIN) continue;
					if ((double)v[i][j] > avg) v[i][j] -= 1;
					else if ((double)v[i][j] < avg) v[i][j] += 1;
				}
			}
		}
	}
	//��� ���� ��ȸ �� ������ ���� ���� ��
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (v[i][j] != INT_MIN) ans += v[i][j];
	return ans;
}

int main() {
	FIO;
	input();
	cout << solve();
	return 0;
}