#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int arr[1001];
int main() {
	int n;
	scanf("%d", &n);
	int minval = 101;
	int maxval = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		minval = min(minval, arr[i]);
		maxval = max(maxval, arr[i]);
	}
	int anst = 0;
	int anscost = 1000000;
	for (int i = minval; i <= maxval; i++) {
		int cost = 0;
		for (int j = 0; j < n; j++) {
			if (abs(arr[j] - i) <= 1) continue;
			else {
				if (arr[j] > i)cost += abs(arr[j] - (i + 1));
				else if (arr[j] < i)cost += abs(arr[j] - (i - 1));
			}
		}
		if (anscost > cost) {
			anst = i;
			anscost = cost;
		}
	}
	printf("%d %d", anst, anscost);
	return 0;
}