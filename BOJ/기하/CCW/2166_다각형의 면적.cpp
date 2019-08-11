#include <stdio.h>
#include <vector>
using namespace std;
vector<pair<double, double>>v;
int main() {
	int n;
	double a, b, ans = 0.0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &a, &b);
		v.push_back({ a,b });
	}
	v.push_back(v[0]);
	for (int i = 0; i < n; i++) ans += v[i].first*v[i + 1].second- v[i + 1].first*v[i].second;
	if (ans < 0)ans *= (-1);
	printf("%.1lf", ans/2);
	return 0;
}