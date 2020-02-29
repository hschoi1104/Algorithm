#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
int sum[200001][27],res[27];
int n, m;
void init() {
	for (int i = 0; i <= n; i++) memset(sum[i], 0, sizeof(sum[i]));
	memset(res, 0, sizeof(res));
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<int>v;
		string s; cin >> s;
		for (int i = 0; i < m; i++) {
			int x; cin >> x; v.push_back(x);
		}
		//get sum array
		sum[1][s[0] - 97] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < 26; j++) sum[i][j] += (sum[i-1][j]);
			sum[i][s[i-1] - 97] += 1;
		}
		int prev = 0;
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < 26; j++) {
				res[j] += (sum[v[i]][j]);
			}
			prev = v[i]-1;
		}
		for (int j = 0; j < 26; j++) {
			res[j] += sum[n][j];
		}
		for (int i = 0; i < 26; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
		init();
	}
	return 0;
}