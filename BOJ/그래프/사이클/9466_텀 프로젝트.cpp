#include <stdio.h>
#include <string.h>
using namespace std;
int arr[100001];
int chk[100001];
int start[100001];
int dfs(int s, int c,int cnt) {
	//현재점이 이미 방문한 점이라면
	if (chk[c]) {
		//그게 시작점이 아니라면 전체 사이클은 아님
		if (start[c] != s) return 0;
		//중간에 사이클이 포함된경우
		return cnt - chk[c];
	}
	//경로를 돌면서 시작한 점의 정보를 유지해줌
	//chk를 초기화 하지 않기 때문에 시작점의 정보가 섞일수 있음
	start[c] = s;
	chk[c] = cnt;
	return dfs(s, arr[c], cnt + 1);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, ans = 0;
		scanf("%d", &n);
		memset(arr, 0, sizeof(arr));
		memset(chk, 0, sizeof(chk));
		memset(start, 0, sizeof(start));
		for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
		for (int i = 1; i <= n; i++) {
			//한번방문한 점은 방문하지 않아도된다.
			if (!chk[i]) {
				int res = dfs(i, i,1);
				ans += res;
			}
		}
		printf("%d\n", n - ans);
	}
	return 0;
}