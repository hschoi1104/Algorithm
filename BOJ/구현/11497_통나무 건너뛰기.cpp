#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int t;
int main() {
	scanf("%d", &t);
	while (t--) {
		int n, x, ans = 0;
		vector<int>v;
		vector<int>v1;
		vector<int>v2;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			v.push_back(x);
		}
		sort(v.begin(), v.end(), greater<int>());
		v1.push_back(v[0]);
		v2.push_back(v[0]);
		for (int i = 1; i < v.size(); i++) {
			if (i % 2 == 0) v1.push_back(v[i]);
			else v2.push_back(v[i]);
		}
		for (int i = 1; i < v1.size(); i++) {
			ans = max(ans, abs(v1[i - 1] - v1[i]));
		}
		for (int i = 1; i < v2.size(); i++) {
			ans = max(ans, abs(v2[i - 1] - v2[i]));
		}
		ans = max(ans, abs(v1[v1.size() - 1] - v2[v2.size() - 1]));
		printf("%d\n", ans);
	}
	return 0;
}