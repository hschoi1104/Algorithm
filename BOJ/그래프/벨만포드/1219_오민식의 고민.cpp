#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll>p;
vector<vector<p>>v;
queue<int>q;
int n, s, e, m;
ll dist[110];
ll profit[110];
int visited[101];
bool cycle = false;

void bellman(int start, int end) {
	fill(dist, dist + 101, INT_MAX);
	dist[start] = 0 + profit[start];
	for (int k = 0; k < n; k++) {
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < v[j].size(); i++) {
				int npos = v[j][i].first;
				ll ncost = v[j][i].second + profit[npos];
				if (dist[j] != INT_MAX && dist[npos] > dist[j] + ncost) {
					dist[npos] = dist[j] + ncost;
					if (k == n - 1) {
						cycle = true;
						q.push(j);
					}
				}
			}
		}
	}
}

int main() {
	scanf("%d %d %d %d", &n, &s, &e, &m);
	v.resize(n + 1);
	//교통수단정보
	for (int i = 0; i < m; i++) {
		int a, b;
		ll c;
		scanf("%d %d %lld", &a, &b, &c);
		v[a].push_back({ b,c });
	}
	//도시에서 얻을수 있는 이윤
	for (int i = 0; i < n; i++) {
		ll x;
		scanf("%lld", &x);
		profit[i] = -x;
	}
	//벨만포드
	bellman(s, e);
	//사이클이있는경우 도착하는가를 확인해주기위함
	if (cycle) {
		while (!q.empty()) {
			int cur = q.front();
			visited[cur] = 1;
			if(cur == e) break;
			q.pop();
			for (int i = 0; i < v[cur].size(); i++) {
				int next = v[cur][i].first;
				if (visited[next] == 0) {
					q.push(next);
					visited[next] = 1;
				}
			}
		}
	}
	//도착가능한경우
	if (dist[e] != INT_MAX) {
		if (visited[e] == 1) printf("Gee");
		else printf("%d", -dist[e]);
	}
	else {
		printf("gg");
	}
	return 0;
}