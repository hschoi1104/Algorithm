#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> p;
vector<p>v;
int main() {
	int n, s, e;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &s, &e);
		v.push_back({ e ,s });
	}
	sort(v.begin(), v.end());
	int prev = 0,ans=0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second >= prev) {
			prev = v[i].first;
			ans += 1;
		}
	}
	printf("%d", ans);
	return 0;
}