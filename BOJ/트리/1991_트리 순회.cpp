#include <stdio.h>
#include <vector>
using namespace std;
vector<vector<int>>g;
void pre(int cur) {
	printf("%c", cur);
	for (int i = 0; i < 2; i++) { int next = g[cur][i]; if (next != '.') pre(next);}
	return;
}
void post(int cur) {
	for (int i = 0; i < 2; i++) { int next = g[cur][i]; if (next != '.') post(next); }
	printf("%c", cur);
	return;
}
void in(int cur) {
	for (int i = 0; i < 2; i++) { int next = g[cur][i];	if (i != 0) { printf("%c", cur); } if (next != '.') in(next); }
	return;
}
int main() {
	g.resize('Z' + 1);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char a, b, c; scanf(" %1c %1c %1c", &a, &b, &c);
		g[a].push_back(b); g[a].push_back(c);
	}
	pre('A'); printf("\n");
	in('A'); printf("\n");
	post('A');
	return 0;
}