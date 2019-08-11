#include <stdio.h>
#include <vector>
using namespace std;
vector<int>v;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) v.push_back(i + 1);
	printf("<");
	int pos = 0;
	while (v.size() != 1) {
		pos += m - 1;
		if (pos >= v.size()) pos %= v.size();
		printf("%d, ", v[pos]);
		v.erase(v.begin() + pos);
	}
	printf("%d>", v[0]);
	return 0;
}