#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<vector<int>>g;
vector<int>v;
void go(int s, int e, int dep) {
	if (s == e) { g[dep].push_back(v[s]); return; }
	int mid = (s + e) / 2;
	g[dep].push_back(v[mid]);
	go(s, mid - 1, dep + 1);
	go(mid + 1, e, dep + 1);
	return;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int k; cin >> k;
	g.resize(k + 1);
	for (int i = 0; i < pow(2, k) - 1; i++) {int a; cin >> a; v.push_back(a);}
	go(0, v.size() - 1, 1);
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < g[i].size(); j++) {cout << g[i][j] << " ";}
		cout << "\n";
	}
	return 0;
}