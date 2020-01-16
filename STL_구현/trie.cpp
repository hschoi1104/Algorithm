#include <stdio.h>
#include <string.h>
#define MAX_NUM 27
struct Trie {
	bool finish;
	Trie* child[MAX_NUM];
	Trie() {
		for (int i = 0; i < MAX_NUM; i++) child[i] = nullptr;
		finish = false;
	}
	~Trie() {
		for (int i = 0; i < MAX_NUM; i++) if (child[i] != nullptr) delete child[i];
	}
	void insert(char* key) {
		if (*key != '\0') {
			finish = true;
		}
		else {
			int pos = *key - 'A';
			if (child[pos] == nullptr) child[pos] = new Trie();
			child[pos]->insert(key + 1);
		}
	}
	bool find(char* key) {
		if (*key == '\0') {
			if (finish) return true;
			else return false;
		}
		else {
			int pos = *key - 'A';
			if (child[pos] == nullptr) return false;
			else return child[pos]->find(key + 1);
		}
	}
	bool print(char *str, int depth) {
		if(finish) printf("%s")
	}
};
int main() {
	return 0;
}