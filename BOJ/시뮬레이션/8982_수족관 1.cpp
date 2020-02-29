#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>wall, water, hole;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a, b; cin >> a >> b;
	for (int i = 0; i < n / 2-1; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		for (int s = a; s < c; s++) wall.push_back(b);
	}
	cin >> a >> b;
	water.resize(wall.size());
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		hole.push_back(a);
	}
	for (int i = 0; i < hole.size(); i++) {
		//аб
		int height = wall[hole[i]];
		for (int j = hole[i]; j >= 0; j--) {
			if (i > 0 && (hole[i - 1] == j)) break;
			height = min(height, wall[j]);
			water[j] = max(water[j], height);
		}
		//©Л
		height = wall[hole[i]];
		for (int j = hole[i]; j < wall.size(); j++) {
			if (i < hole.size() - 1 && (hole[i + 1] == j)) break;
			height = min(height, wall[j]);
			water[j] = max(water[j], height);
		}
	}

	int ans = 0;
	for (int i = 0; i < water.size(); i++) {
		if (water[i] - wall[i] < 0) ans += wall[i]-water[i];
	}
	cout << ans;
	return 0;
}