#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> p;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		vector<p>v;
		int n, a, b, res = 0, ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			v.push_back({ n + 1 - a,n + 1 - b });
		}
		sort(v.begin(), v.end(), greater<p>());
		for (int i = 0; i < v.size(); i++) {
			if (res < v[i].second) {
				res = v[i].second;
				ans += 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}