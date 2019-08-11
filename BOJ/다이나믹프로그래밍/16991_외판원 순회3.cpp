#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
#define INT_MA 999999999
using namespace std;
typedef pair<int, int> p;
double arr[20][20];
double dp[20][1 << 16];
int n, a, b;
vector<p>v;
double go(int cur, int visited) {
	double& ret = dp[cur][visited];
	if (ret != -1.0) return ret;
	if (visited == (1 << n) - 1) {
		if (arr[cur][0] != 0.0) return arr[cur][0];
		return INT_MA;
	}
	ret = INT_MA;
	for (int i = 0; i < n; i++) {
		if ((visited & (1 << i)) != 0.0 || arr[cur][i] == 0.0) continue;
		ret = min(ret, go(i, visited | (1 << i)) + arr[cur][i]);
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		v.push_back({ a,b });
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			arr[i][j] = sqrt(pow(v[i].first - v[j].first, 2) + pow(v[i].second - v[j].second, 2));
		}
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < (1 << 16); j++) {
			dp[i][j] = -1.0;
		}
	}
	printf("%lf\n", go(0, 1));
	return 0;
}