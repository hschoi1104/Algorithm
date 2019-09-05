#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int fre[11][11];
int chk[10];
int n, m;
void init() {
	memset(fre, 0, sizeof(fre));
	memset(chk, 0, sizeof(chk));
}
int findF() {
	for (int i = 0; i < n; i++) if (chk[i] == 0) return i;
	return -1;
}
int go() {
	if (findF() == -1) return 1;
	int now = findF();
	chk[now] = 1;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		int next = i;
		if (chk[next] == 0 && fre[now][i] && now<=next) {
			chk[next] = 1;
			ret += go();
			chk[next] = 0;
		}
	}
	chk[now] = 0;
	return ret;
}
int main() {
	int c; cin >> c;
	while (c--) {
		init();
		 cin >> n >> m;
		 for (int i = 0; i < m; i++) {
			 int a, b; cin >> a >> b;
			 fre[a][b] = fre[b][a] = 1;
		 }
		 cout<< go()<<"\n";
	}
	return 0;
}