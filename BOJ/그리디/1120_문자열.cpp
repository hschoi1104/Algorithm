#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int ans = 51;
	for (int i = 0; i < b.length()-a.length()+1; i++) {
		int res = 0;
		for (int j = 0; j < a.length(); j++) {
			if (b[i + j] != a[j]) res += 1;
		}
		ans = min(ans, res);
	}
	printf("%d", ans);
	return 0;
}