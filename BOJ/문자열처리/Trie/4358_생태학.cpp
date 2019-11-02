#include <stdio.h>
#include <algorithm>
#define max_len 95
using namespace std;
int n, m = 0;
struct Trie {
	bool finish;
	int cnt;
	Trie* child[max_len];
	Trie() {
		finish = false; cnt = 0;
		fill(child, child + max_len, nullptr);
	}
	~Trie() {
		for (int i = 0; i < max_len; i++) if (child[i]) delete child[i];
	}
	void insert(char* key) {
		if (*key == '\0') {
			finish = true;
			cnt += 1;
			return;
		}
		else {
			int next = *key - ' ';
			if (!child[next]) child[next] = new Trie;
			child[next]->insert(key + 1);
		}
	}
	void travel(char* str, int depth) {
		if (finish) {
			printf("%s %.4lf", str, (double)cnt / (double)m * 100);
		}
		for (int i = 0; i < max_len; i++) {
			if (child[i]) {
				str[depth] = i + ' ';
				str[depth + 1] = '\0';
				child[i]->travel(str, depth + 1);
			}
		}
	}
};
int main() {
	Trie* root = new Trie;
	char str[31], ch[31];
	//scanf("%[^\n]", ch)
	while (scanf("%[^\n]", ch)!=EOF) {
		getchar();
		m += 1;
		root->insert(ch);
	}
	root->travel(str, 0);
	delete root;
	return 0;
}