#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>v;
vector<int>ans;
int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		v.push_back(x);
	}
	ans.push_back(v[0]);
	for (int i = 1; i < v.size(); i++) {
		if (ans.back() < v[i]) ans.push_back(v[i]);
		else {
			auto it = lower_bound(ans.begin(), ans.end(),v[i]);
			*it = v[i];
		}
	}
	printf("%d", ans.size());
	return 0;
}