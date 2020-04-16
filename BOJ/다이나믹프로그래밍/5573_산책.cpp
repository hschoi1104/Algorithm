#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define p pair<int, int>
using namespace std;
int n, m, c, a[1010][1010], dp[1010][1010];

p update(int y, int x) {
    if (y > n || x > m) return {y, x};
    p res;
    if (a[y][x] == 1) return res = update(y, x + 1);
    else return res = update(y + 1, x);
}

void go() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j]) {
                dp[i + 1][j] += dp[i][j] / 2;
                dp[i][j + 1] += (dp[i][j] % 2 ? dp[i][j] / 2 + 1 : dp[i][j] / 2);
            } else {
                dp[i + 1][j] += (dp[i][j] % 2 ? dp[i][j] / 2 + 1 : dp[i][j] / 2);
                dp[i][j + 1] += dp[i][j] / 2;
            }
        }
    }
}

int main() {
    FIO;
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];

    dp[1][1] = c - 1;
    go();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            a[i][j] += dp[i][j];
            a[i][j] %= 2;
        }


    p res = update(1, 1);
    cout << res.first << " " << res.second;

    return 0;
}