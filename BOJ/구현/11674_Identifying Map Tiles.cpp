#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;
char arr[40];
int main() {
	scanf("%s",&arr);
	int len = strlen(arr);
	int ms = pow(2, len);
	int x=0, y = 0;
	for (int i = 0; i < len; i++) {
		if (arr[i] == '0') {
			x += 0;
			y += 0;
		}
		else if (arr[i] == '1') {
			x += ms / 2;
		}
		else if (arr[i] == '2') {
			y += ms / 2;
		}
		else if (arr[i] == '3') {
			x += ms / 2;
			y += ms / 2;
		}
		ms /= 2;
	}
	printf("%d %d %d\n",len, x, y);
	return 0;
}