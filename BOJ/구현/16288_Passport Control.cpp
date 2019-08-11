#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[101];
bool chk[101];
int main() {
	int n, k,cnt=0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	while (1) {
		bool flag = false;
		int val = -1;
		for (int i = 0; i < n; i++) {
			if (chk[i] == true) continue;
			else if(val == -1 || val < arr[i]) {
				chk[i] = true;
				val = arr[i];
				flag = true;
			}
		}
		if (flag == false) break;
		cnt++;
	}
	if (cnt <= k) printf("YES");
	else printf("NO");
	return 0;
}