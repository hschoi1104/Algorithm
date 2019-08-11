#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int ptr_num = 27;

struct Trie {
	Trie* child[ptr_num];
	bool finish, haveChild;
	Trie() {
		fill(child, child + ptr_num, nullptr);
		finish = haveChild = false;
	}
	~Trie() {
		for (int i = 0; i < ptr_num; i++) if (child[i]) delete child[i];
	}
	void insert(char* key) {
		if (*key == '\0') finish = true;
		else {
			int next = *key - 'a';
			if (!child[next]) child[next] = new Trie;
			haveChild = true;
			child[next]->insert(key + 1);
		}
	}
	bool find(char* key) {
		if (*key == '\0') {
			return finish;
		}
		int next = *key - 'a';
		if (!child[next]) return false;
		child[next]->find(key + 1);
	}
};

int main() {
	int n, m, ans = 0;
	scanf("%d %d", &n,&m);
	Trie* root = new Trie;
	bool res = true;
	for (int i = 0; i < n; i++) {
		char num[501];
		scanf("%s", num);
		root->insert(num);
	}
	for (int i = 0; i < m; i++) {
		char num[501];
		scanf("%s", num);
		if (root->find(num))ans += 1;
	}
	printf("%d", ans);
	delete root;
	return 0;
}