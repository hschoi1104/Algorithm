#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(),cout.tie();
using namespace std;
int a[501][501], n;

int main() {
    FIO;
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= i; j++) cin >> a[i][j];

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++) {
            a[i][j] += max(a[i - 1][j - 1], a[i - 1][j]);
        }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, a[n][i]);
    cout << ans;
    return 0;
}
