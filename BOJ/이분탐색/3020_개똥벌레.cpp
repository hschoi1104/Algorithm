#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
vector<int>up;
vector<int>down;
int ans[500001];
int main() {
	int n, h, a, b;
	scanf("%d %d", &n, &h);
	for (int i = 0; i < n / 2; i++) {
		scanf("%d %d", &a, &b);
		down.push_back(a);
		up.push_back(b);
	}
	sort(down.begin(), down.end());
	sort(up.begin(), up.end());

	int cnt = INT_MAX;
	for (int i = 1; i <= h; i++) {
		int temp = n/2-(lower_bound(up.begin(), up.end(), i)-up.begin());
		temp += n / 2 - (lower_bound(down.begin(), down.end(), h-i+1) - down.begin());
		ans[i] = temp;
		cnt = min(cnt, temp);
	}
	int range = 0;
	for (int i = 1; i <= h; i++) {
		if (ans[i] == cnt) range += 1;
	}
	printf("%d %d\n", cnt, range);
	return 0;
}