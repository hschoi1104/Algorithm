#include <stdio.h>
#define MAX_LEN 27
struct Trie {
	bool finish;
	Trie* child[MAX_LEN];

	Trie() {
		finish = false;
		for (int i = 0; i < MAX_LEN; i++) child[i] = nullptr;
	}
	~Trie() {
		for (int i = 0; i < MAX_LEN; i++) if (child[i]) delete child[i];
	}

	void insert(char* key) {
		if (*key == '\0') {
			finish = true;
		}
		else {
			int pos = *key - 'A';
			if (!child[pos]) child[pos] = new Trie;
			child[pos]->insert(key + 1);
		}
	}
	bool find(char* key) {
		if (*key == '\0') {
			if (finish) return true;
			return false;
		}
		else {
			int pos = *key - 1;
			if (!child[pos]) return false;
			child[pos]->find(key + 1);
		}
	}
	void print(char* str, int depth) {
		if (finish) printf("%s\n", str);
		for (int i = 0; i < MAX_LEN; i++) {
			str[depth] = i + 'A';
			str[depth + 1] = '\0';
			if (child[i]) child[i]->print(str, depth + 1);
		}
	}
};

int main() {
	Trie* root = new Trie();
	for (int i = 0; i < 3; i++) {
		char ch[15];
		scanf("%s", ch);
		root->insert(ch);
	}
	char str[20];
	root->print(str, 0);
	return 0;
}