#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>stone;
int main() {
	int x, m, k, sum = 0; scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		stone.push_back(x);
		sum += x;
	}
	scanf("%d", &k);
	double res=0.0;
	for (int i = 0; i < stone.size(); i++) {
		double temp=1.0;
		double kk = sum;
		double tt=stone[i];
		if (k > stone[i]) continue;
		for (int j = 0; j < k; j++) {
			temp *= (tt-j) / (kk-j);
		}
		res += temp;
	}
	printf("%.10lf", res);
	return 0;
}