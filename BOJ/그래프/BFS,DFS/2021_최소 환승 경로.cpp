#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
vector<vector<int>>route;
vector<vector<int>>station;
bool chkroute[100001];
int chkstation[100001];
int n, l, x, s, e;
queue < int >q;
int bfs(int s, int e) {
	q.push(s);
	for (int i = 0; i < station[s].size(); i++) {
		int croute = station[s][i];
		chkroute[croute] = true;
		for (int j = 0; j < route[croute].size(); j++) {
			int cstation = route[croute][j];
			chkstation[cstation] = 1;
			q.push(cstation);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		if (cur == e) return chkstation[cur] - 1;
		q.pop();
		for (int i = 0; i < station[cur].size(); i++) {
			int nroute = station[cur][i];
			if (chkroute[nroute]) continue;
			chkroute[nroute] = true;
			for (int j = 0; j < route[nroute].size(); j++) {
				int nstation = route[nroute][j];
				if (nstation == cur || chkstation[nstation]) continue;
				q.push(nstation);
				chkstation[nstation] = chkstation[cur]+1;
				if (nstation == e) return chkstation[nstation] - 1;
			}
		}
	}
	return -1;
}
int main() {
	scanf("%d %d", &n, &l);
	station.resize(n + 1);
	route.resize(l + 1);
	//노선 및 역 정보 입력
	for (int i = 1; i <= l; i++) {
		while (1) {
			scanf("%d", &x);
			if (x == -1) break;
			route[i].push_back(x);
			station[x].push_back(i);
		}
	}
	scanf("%d %d", &s, &e);

	printf("%d", bfs(s, e));
	return 0;
}