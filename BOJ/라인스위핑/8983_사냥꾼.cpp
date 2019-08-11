#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>>v;
vector<int>f;
int main() {
	int M, N, L;
	scanf("%d %d %d", &M, &N, &L);
	for (int i = 0; i < M; i++) {
		int x;
		scanf("%d", &x);
		f.push_back(x);
	}
	sort(f.begin(), f.end());
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (y > L) continue;
		int mi = x + y - L;
		int ma = x - y + L;
		int left = 0;
		int right = f.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (mi <= f[mid] && f[mid] <= ma) {
				cnt++;
				break;
			}
			if (mi > f[mid]) left = mid + 1;
			else right = mid - 1;
		}
	}
	printf("%d\n", cnt);
	return 0;
}