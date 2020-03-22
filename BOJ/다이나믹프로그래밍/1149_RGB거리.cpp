#include <bits/stdc++.h>
using namespace std;
int a[1001][3], n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];

    for (int i = 1; i < n; i++) {
        a[i][0] += min(a[i - 1][1], a[i - 1][2]);
        a[i][1] += min(a[i - 1][0], a[i - 1][2]);
        a[i][2] += min(a[i - 1][0], a[i - 1][1]);
    }
    cout << min(a[n - 1][0], min(a[n - 1][1], a[n - 1][2]));
    return 0;
}
