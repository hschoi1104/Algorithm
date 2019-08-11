#include <stdio.h>
using namespace std;
int arr[51][51];
int res[51][51];
int n, m,ans=0;
void change(int y, int x) {
	for (int i = y; i < y + 3; i++) for (int j = x; j < x + 3; j++) arr[i][j] = (arr[i][j] == 1) ? 0 : 1;
	ans += 1;
	return;
}
bool chk() {
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (arr[i][j] != res[i][j]) return false;
	return true;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%1d", &arr[i][j]);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%1d", &res[i][j]);

	for (int j = 0; j <= m - 3; j++) for (int i = 0; i <= n - 3; i++) if (arr[i][j] != res[i][j]) change(i, j);
	
	printf("%d", (chk() == false) ? -1 : ans);
	return 0;
}