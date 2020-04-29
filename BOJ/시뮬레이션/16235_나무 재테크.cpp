#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FORIJ(a,b) for(int i=a;i<b;i++) for(int j=a;j<b;j++)
using namespace std;
vector<int>p[11][11];
int f[11][11], a[11][11], dir[8][2] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} }, n, m, k, x, y, z, ans;

int main() {
	FIO;
	cin >> n >> m >> k;
	FORIJ(1, n + 1) {
		cin >> a[i][j];
		f[i][j] = 5;
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		p[x][y].push_back(z);
	}

	while (k--) {
		FORIJ(1, n + 1) {
			bool dead = false;
			vector<int>v;
			sort(p[i][j].begin(), p[i][j].end());
			for (auto it : p[i][j]) {
				if (it > f[i][j] || dead) {
					f[i][j] += (it / 2);
					dead = true;
					continue;
				}
				f[i][j] -= it;
				v.push_back(it);
			}
			p[i][j].clear();
			for (auto it : v) p[i][j].push_back(it + 1);
			v.clear();
		}
		FORIJ(1, n + 1) {
			for (auto it : p[i][j]) {
				if (it % 5 == 0) {
					for (int w = 0; w < 8; w++) {
						int ny = i + dir[w][0], nx = j + dir[w][1];
						if (1 <= ny && ny <= n && 1 <= nx && nx <= n) p[ny][nx].push_back(1);
					}
				}
			}
		}
		FORIJ(1, n + 1) f[i][j] += a[i][j];
	}
	FORIJ(1, n + 1) ans += p[i][j].size();
	cout << ans;
	return 0;
}