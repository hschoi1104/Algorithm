#include <stdio.h>
#include <algorithm>
using namespace std;
int game[1001];
int referee[1001];
int vote[1001];
int n, m,ans=0;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)scanf("%d", &game[i]);
	for (int i = 0; i < m; i++)scanf("%d", &referee[i]);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (referee[i] >= game[j]) {
				vote[j] += 1;
				ans = max(ans, vote[j]);
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) if (vote[i] == ans) printf("%d", i+1);
	return 0;
}