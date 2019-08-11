#include <stdio.h>
#include <algorithm>
using namespace std;
typedef pair<int, int>p; //°ª,¼ø¼­
p arr[100001];
int ans = 0;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].first);
		arr[i].second = i;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		ans = max(ans, arr[i].second - i);
	}
	printf("%d", ans + 1);
}
