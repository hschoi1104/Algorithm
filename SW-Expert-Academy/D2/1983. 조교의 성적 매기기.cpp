#include <stdio.h>
double arr[101];
char grade[3];
void qsort(int s, int e) {
    if (s >= e) return;
    int pivot = s;
    int i = pivot + 1;
    int j = e;
    double tmp;
    while (i <= j) {
        while (i <= e && arr[i] <= arr[pivot]) i++;
        while (j > s&& arr[j] >= arr[pivot]) j--;
        if (i > j) {
            tmp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = tmp;
        }
        else {
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
        }
    }
    qsort(s, j - 1);
    qsort(j + 1, e);
}
void go(int i, int n) {
    int v = i / (n / 10);
    if (v == 9) { grade[0] = 'A'; grade[1] = '+'; }
    if (v == 8) { grade[0] = 'A'; grade[1] = '0'; }
    if (v == 7) { grade[0] = 'A'; grade[1] = '-'; }
    if (v == 6) { grade[0] = 'B'; grade[1] = '+'; }
    if (v == 5) { grade[0] = 'B'; grade[1] = '0'; }
    if (v == 4) { grade[0] = 'B'; grade[1] = '-'; }
    if (v == 3) { grade[0] = 'C'; grade[1] = '+'; }
    if (v == 2) { grade[0] = 'C'; grade[1] = '0'; }
    if (v == 1) { grade[0] = 'C'; grade[1] = '-'; }
    if (v == 0) { grade[0] = 'D'; grade[1] = '0'; }
    return;
}
int main() {
    int t; scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        int n, k; scanf("%d %d", &n, &k);
        double tmp;
        for (int i = 0; i < n; i++) {
            double a, b, c; scanf("%lf %lf %lf", &a, &b, &c);
            arr[i] = a * 0.35 + b * 0.45 + c * 0.2;
        }
        tmp = arr[k - 1];
        qsort(0, n - 1);
        for (int i = 0; i < n; i++) {
            if (arr[i] == tmp) {
                go(i, n);
                printf("#%d %s\n", tt, grade);
                break;
            }
        }
    }
    return 0;
}