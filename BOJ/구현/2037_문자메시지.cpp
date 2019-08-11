#include <iostream>
#include <string>
using namespace std;
int arr[27] = { 1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4 };
int point[27] = { 1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,6,7,7,7,8,8,8,8 };
int main() {
	int p, w, ans = 0;
	string s;
	scanf("%d %d", &p, &w);
	cin.ignore();
	getline(cin, s);
	int prevpoint = -1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			ans += p;
			prevpoint = -1;
			continue;
		}
		ans += (p*arr[s[i] - 65]);
		int curpoint = point[s[i] - 65];
		if (prevpoint == curpoint) ans += w;
		else prevpoint = curpoint;
	}
	printf("%d", ans);
	return 0;
}