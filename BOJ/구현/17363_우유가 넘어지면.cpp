#include <stdio.h>
using namespace std;
char a[101][101], b[101][101];
int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &a[i][j]);
		}
	}
	int ii = 0, jj = 0;
	for (int j = m - 1; j >= 0; j--) {
		for (int i = 0; i < n; i++) {
			b[ii][jj++] = a[i][j];
			jj %= n;
		}
		ii++;
		ii %= m;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (b[i][j] == '-') printf("|");
			else if (b[i][j] == '|') printf("-");
			else if (b[i][j] == '/') printf("\\");
			else if (b[i][j] == '\\') printf("/");
			else if (b[i][j] == '^') printf("<");
			else if (b[i][j] == '<') printf("v");
			else if (b[i][j] == 'v') printf(">");
			else if (b[i][j] == '>') printf("^");
			else printf("%1c", b[i][j]);
		}
		printf("\n");
	}

}