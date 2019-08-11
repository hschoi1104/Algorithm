#include <stdio.h>
int arr[9];
int brr[9];
bool isWin = false;
int asum = 0;
int bsum = 0;

int main() {
	for (int i = 0; i < 9; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < 9; i++)	scanf("%d", &brr[i]);
	for (int i = 0; i < 9; i++) {
		asum += arr[i];
		if (asum > bsum) isWin = true;
		bsum += brr[i];
		if (i == 8) {
			if (asum < bsum && isWin) printf("Yes");
			else printf("No");
		}
	}
	return 0;
}