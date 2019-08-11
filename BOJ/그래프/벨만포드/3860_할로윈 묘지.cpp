#include <iostream>
#include <vector>
using namespace std;
typedef struct node {
	int x1, y1, x2, y2, t;
};
int arr[31][31], dist[31][31], INF = 999999999;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1 } };
vector<node>edge;
int main() {
	while (1) {
		int w, h, g, e, x, y; cin >> w >> h;
		if (w == 0 && h == 0) break;
		//map 초기화
		for (int i = 0; i <= 30; i++) for (int j = 0; j <= 30; j++) arr[i][j] = 0;
		edge.clear();

		//무덤 체크
		cin >> g;
		for (int i = 0; i < g; i++) {
			cin >> x >> y;
			arr[y][x] = 1;
		}
		//귀신구멍 체크
		cin >> e;
		for (int i = 0; i < e; i++) {
			node temp;
			cin >> temp.x1 >> temp.y1 >> temp.x2 >> temp.y2 >> temp.t;
			edge.push_back(temp);
			arr[temp.y1][temp.x1] = 2;
		}
		arr[h - 1][w - 1] = 2;
		//인접리스트로 재구성
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == 2) continue;
				for (int k = 0; k < 4; k++) {
					int dy = i + dir[k][0];
					int dx = j + dir[k][1];
					if (0 <= dy && dy < h && 0 <= dx && dx < w && arr[i][j] != 1) {
						node t = { j,i,dx,dy,1 };
						edge.push_back(t);
					}
				}
			}
		}

		//벨만포드 초기화
		for (int i = 0; i <= h; i++) for (int j = 0; j <= w; j++) dist[i][j] = INF;
		dist[0][0] = 0;
		//음의 사이클 체크
		bool update = false;
		//모든 정점 수 만큼 반복
		for (int i = 0; i < w * h; i++) {
			update = false;
			//모든 에지 반복
			for (auto it : edge) {
				if (dist[it.y1][it.x1] == INF) continue;
				if (dist[it.y2][it.x2] > dist[it.y1][it.x1] + it.t) {
					dist[it.y2][it.x2] = dist[it.y1][it.x1] + it.t;
					update = true;
				}
			}
		}
		if (update == true) cout << "Never\n";
		else if (dist[h - 1][w - 1] == INF) cout << "Impossible\n";
		else cout << dist[h - 1][w - 1] << "\n";

	}
	return 0;
}