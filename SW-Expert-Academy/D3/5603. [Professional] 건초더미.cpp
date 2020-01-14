#include <iostream>
using namespace std;

int main() {
	int tt; cin >> tt;
	for (int t = 1; t <= tt; t++) {
		int n, sum = 0, ans = 0; cin >> n;
		int* arr = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		sum = sum / n;
		for (int i = 0; i < n; i++) {
			if (arr[i] > sum) ans += (arr[i] - sum);
		}
		cout << "#" << t << " " << ans << "\n";
		free(arr);
	}
	return 0;
}
//#include <iostream>
//using namespace std;
//
//void qsort(int* arr, int s, int e) {
//	if (s >= e) return;
//	int pivot = s;
//	int i = pivot + 1;
//	int j = e;
//	int tmp;
//	while (i <= j) {
//		while (i <= e && arr[i] <= arr[pivot]) i++;
//		while (j > s&& arr[j] >= arr[pivot]) j--;
//		if (i > j) {
//			tmp = arr[j];
//			arr[j] = arr[pivot];
//			arr[pivot] = tmp;
//		}
//		else {
//			tmp = arr[j];
//			arr[j] = arr[i];
//			arr[i] = tmp;
//		}
//	}
//	qsort(arr, s, j - 1);
//	qsort(arr, j + 1, e);
//}
//int main() {
//	int tt; cin >> tt;
//	for (int t = 1; t <= tt; t++) {
//		int n, sum = 0, ans = 0; cin >> n;
//		int* arr = (int*)malloc(sizeof(int) * n);
//		for (int i = 0; i < n; i++) {
//			scanf("%d", &arr[i]);
//			sum += arr[i];
//		}
//		qsort(arr, 0, n - 1);
//		sum = sum / n;
//		int i = 0, j = n - 1;
//		while (i < j) {
//			if (arr[j] == sum || arr[i] == sum) break;
//			int tmp = arr[j] - sum;
//			while (tmp != 0) {
//				if (tmp > sum - arr[i]) {
//					ans += (sum - arr[i]);
//					arr[j] -= (sum - arr[i]);
//					tmp -= (sum - arr[i]);
//					arr[i] += (sum - arr[i]);
//					i++;
//				}
//				else if (tmp == sum - arr[i]) {
//					ans += (sum - arr[i]);
//					arr[j] -= (sum - arr[i]);
//					arr[i] += (sum - arr[i]);
//					tmp = 0;
//					j--; i++;
//				}
//				else {
//					ans += tmp;
//					arr[i] += tmp;
//					arr[j] -= tmp;
//					tmp = 0;
//					j--;
//				}
//			}
//		}
//		cout << "#" << t << " " << ans << "\n";
//		free(arr);
//	}
//	return 0;
//}