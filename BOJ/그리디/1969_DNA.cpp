#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int chk[90], d[4] = { 'A','C','G','T' }, cnt;
vector<string>v;
string ans;
int main() {
	FIO;
	int n, m; cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	for (int i = 0; i < m; i++) {
		memset(chk, 0, sizeof(chk));
		for (int j = 0; j < n; j++) chk[v[j][i]] += 1;
		int tmp = 0;
		for (int k = 0; k < 4; k++) tmp = max(tmp, chk[d[k]]);
		for (int k = 0; k < 4; k++) if (tmp == chk[d[k]]) {
			ans += d[k];
			cnt += n - chk[d[k]];
			break;
		}
	}
	cout << ans << "\n" << cnt;
	return 0;
}