#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <unordered_map>;
using namespace std;
unordered_map<int, int>um;
int a, b, tt = 1,root,sum;
int main() {
	while (1) {
		root = sum = 0;
		um.clear();
		while (scanf("%d %d", &a, &b)) {
			if (a == -1 && b == -1) break;
			if (a == 0 && b == 0) break;
			um[a] += 0; um[b] += 1;
		}
		if (a == -1 && b == -1) break;

		bool ans = true;
		//chk.1 indegree==0 인것은 1개만 존재해야함
		for (auto it : um) if (it.second == 0) root += 1;
		if (root != 1) ans = false;
		//chk.2 indegree>=2 일 수 없음.
		for (auto it : um) if (it.second >= 2) ans = false;
		//chk.3 edge == N-1개
		for (auto it : um) sum += it.second;
		if (sum != um.size() - 1) ans = false;

		if (um.size() == 0 || ans) printf("Case %d is a tree.\n", tt++);
		else printf("Case %d is not a tree.\n", tt++);
	}
	return 0;
}