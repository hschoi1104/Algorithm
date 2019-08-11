#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, int>m;
map<string, bool>chk;
int main() {
	int n,cp=0,wp=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b, c, d, e, f;
		string name;
		scanf("%d", &a);
		cin.ignore();
		cin >> name;
		scanf("%d %d %d %d %d", &b, &c, &d, &e, &f);
		if (name == "megalusion") continue;
		if (b == 4 && chk[name]!=true) {
			wp += m[name];
			cp += 1;
			chk[name] = true;
		}
		else m[name] += 1;
	}
	if (cp == 0) printf("0");
	else printf("%.10lf", (double)cp / ((double)cp + (double)wp) * 100.0);
	return 0;
}