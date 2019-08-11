#include <stdio.h>
#include <string.h>
char name[1001][1001];
char good[101][31];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		char s[1001];
		scanf("%s", &s);
		int len = strlen(s);
		for (int j = 0; j < len; j++) {
			if (s[j] >= 97 && s[j] <= 122) name[i][j]=s[j];
			else name[i][j]=s[j]+32;
		}
	}
	for (int i = 0; i < m; i++) {
		char s[101];
		scanf("%s", &s);
		int len = strlen(s);
		for (int j = 0; j < len; j++) {
			if (s[j] >= 97 && s[j] <= 122) good[i][j] = s[j];
			else good[i][j] = s[j] + 32;
		}
	}
	for (int i = 0; i < n; i++) {//소이름
		int cnt = 0;
		int len = strlen(name[i]);
		for (int j = 0; j < m; j++) {//좋은단어
			int index = 0;
			int goodlen = strlen(good[j]);
			for (int u = 0; u < len; u++) {
				if (name[i][u] == good[j][index]) index+=1;
			}
			if (index == goodlen) cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}