#include <stdio.h>
#include <algorithm>
const int max_num = 27;
using namespace std;
int ans = 0;
struct Trie {
	Trie* child[max_num];
	bool finish;
	bool havechild;
	int cnt;
	Trie() {
		fill(child, child + max_num, nullptr);
		finish = havechild = false;
		cnt = 0;
	}
	~Trie() {
		for (int i = 0; i < max_num; i++) if (child[i]) delete child[i];
	}
	void insert(char* key) {
		if (*key == '\0') {
			finish = true;
			return;
		}
		else {
			int next = *key - 'a';
			if (!child[next]) child[next] = new Trie;
			havechild = true;
			child[next]->cnt += 1;
			child[next]->insert(key + 1);
		}
	}
	void travel() {

		for (int i = 0; i < max_num; i++) {
			if (child[i]) {
				if (cnt != child[i]->cnt) {
					ans += child[i]->cnt;
				}
				child[i]->travel();
			}
		}
		return;
	}
};

int main() {
	int n;
	while (scanf("%d", &n) != -1) {
		Trie* root = new Trie();
		for (int i = 0; i < n; i++) {
			char arr[81];
			scanf("%s", arr);
			root->insert(arr);
		}
		root->travel();
		printf("%.2lf\n", (double)ans / (double)n);
		delete root;
		ans = 0;
	}
	return 0;
}