#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>v;
int main() {
	int n, x, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) ans += v[i] * (v.size() - i);
	printf("%d", ans);
	return 0;
}