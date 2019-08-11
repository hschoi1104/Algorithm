#include <stdio.h>
int main() {
	char arr[201];
	scanf("%s", arr);
	for (int i = 0; arr[i] != '\0'; i++) {
		printf("%d ", arr[i] - 'A'+1);
	}
	return 0;
}