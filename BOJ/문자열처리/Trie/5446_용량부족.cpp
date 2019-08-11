#include <stdio.h>
#include <algorithm>
const int max_num = 78;
using namespace std;
int ans = 0;
struct Trie {
	Trie* child[max_num];
	bool finish;
	bool chk;
	int cnt;
	Trie() {
		fill(child, child + max_num, nullptr);
		finish = chk = false;
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
			int next = *key - '.';
			if (!child[next]) child[next] = new Trie;
			child[next]->cnt += 1;
			child[next]->insert(key + 1);
		}
	}
	void chkinsert(char* key) {
		int next = *key - '.';
		if (*key == '\0' || !child[next]) {
			return;
		}
		else {
			child[next]->chk = true;
			child[next]->chkinsert(key + 1);
		}
	}
	void travel() {

		for (int i = 0; i < max_num; i++) {
			if (child[i]) {
				if (child[i]->chk) {
					if (child[i]->finish) ans += 1;
					child[i]->travel();
				}
				else {
					ans += 1;
				}
			}
		}
		return;
	}
};

int main() {
	int n, m, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		Trie* root = new Trie();
		for (int i = 0; i < n; i++) {
			char arr[81];
			scanf("%s", arr);
			root->insert(arr);
		}
		root->chk = true;
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			char arr[81];
			scanf("%s", arr);
			root->chkinsert(arr);
		}
		if (m == 0) ans = 1;
		else root->travel();

		printf("%d\n", ans);
		delete root;
		ans = 0;
	}
	return 0;
}