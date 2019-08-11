#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
vector<vector<ll>>v;
queue<ll>q;
ll in[123460];
ll val[123460];
void bfs() {
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			in[next]--;
			if (val[cur] > 0){
				val[next] += val[cur];
				//if (val[next] < 0) val[next] = 0;
			}
			if (in[next] == 0) q.push(next);
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	v.resize(n + 2);
	for (int i = 2; i <= n; i++) {
		char c;
		ll va, x;
		scanf(" %c %lld %lld", &c, &va, &x);
		v[i].push_back(x);
		in[x] += 1;
		if (c == 'S') val[i] = va;
		else val[i] = -va;
	}
	for (int i = 2; i <= n; i++) if (in[i] == 0) q.push(i);
	bfs();
	printf("%lld", val[1]);
	return 0;
}