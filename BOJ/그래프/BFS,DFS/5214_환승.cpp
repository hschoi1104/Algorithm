#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<vector<int>>hyper_station;
vector<vector<int>>station_hyper;
int hyper_chk[1001];
int station_chk[100001];
int n, k, m, x;
int bfs(int cur) {
	queue<pair<int, int>>q;
	q.push({ cur, 1 });
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		if (cur == n) return cnt;
		station_chk[cur] = 1;
		q.pop();
		for (int i = 0; i < station_hyper[cur].size(); i++) {
			int hyper = station_hyper[cur][i];
			if (hyper_chk[hyper] == 1)continue;
			hyper_chk[hyper] = 1;
			for (int j = 0; j < hyper_station[hyper].size(); j++) {
				int station = hyper_station[hyper][j];
				if (station_chk[station] == 1)continue;
				station_chk[station] = 1;
				q.push({ station,cnt + 1 });
				if (station == n) return cnt + 1;
			}
		}
	}
	return -1;
}
int main() {
	scanf("%d %d %d", &n, &k, &m);
	hyper_station.resize(m + 1);
	station_hyper.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= k; j++) {
			scanf("%d", &x);
			hyper_station[i].push_back(x);
			station_hyper[x].push_back(i);
		}
	}

	printf("%d", bfs(1));
	return 0;
}