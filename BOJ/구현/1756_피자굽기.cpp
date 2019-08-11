#include <stdio.h>
using namespace std;
int arr[300001];
int main() {
	int n, k, x, prev = -1;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (prev == -1) {
			prev = arr[i];
		}
		else {
			if (arr[i] > prev) arr[i] = prev;
			else prev = arr[i];
		}
	}
	int pos = n - 1, ans = 0, chk = 0;
	for (int i = 0; i < k; i++) {
		scanf("%d", &x);
		while (pos >= 0) {
			if (arr[pos] >= x) {
				ans = pos--;
				chk += 1;
				break;
			}
			else {
				pos--;
			}
		}
	}
	if(chk == k) printf("%d", ans + 1);
	else printf("0");
	return 0;
}