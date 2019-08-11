#include <iostream>
#include <algorithm>
#include <string.h>
#include <limits.h>
#define INF LLONG_MAX
using namespace std;
typedef long long ll;
ll map[102][102];
ll human[102];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, p, q;
		scanf("%d %d %d", &n, &p, &q);
		//init map
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				if (i == j) map[i][j] = 0;
				else map[i][j] = INF;
			}
		}
		memset(human, 0, sizeof(human));
		//사람입력
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &human[i]);
		}
		//은하길입력
		for (int i = 0; i < q; i++) {
			ll a, b, c;
			scanf("%lld %lld %lld", &a, &b, &c);
			map[a][b] = min(map[a][b], c);
			map[b][a] = min(map[b][a], c);
		}
		//플로이드
		for (int k = 1; k <= p; k++) {
			for (int i = 1; i <= p; i++) {
				for (int j = 1; j <= p; j++) {
					if (map[i][k] != INF && map[k][j] != INF && map[i][j] > map[i][k] + map[k][j]) map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
		pair<ll, ll> ans = { INF,1 };
		//미팅장소
		for (int i = 1; i <= p; i++) {
			ll sum = 0;
			//사람
			bool flag = false;
			for (int j = 1; j <= n; j++) {
				if (map[human[j]][i] != INF) sum += (map[human[j]][i] * map[human[j]][i]);
				else flag = true;
			}
			if (flag == true) continue;
			if (ans.first > sum) ans = { sum,i };
		}
		printf("%lld %lld\n", ans.second, ans.first);
	}
	return 0;
}