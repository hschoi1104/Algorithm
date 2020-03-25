#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(),cout.tie();
using namespace std;
int n, dp[101][10][10][10][2];
string from, to;

int MOD(int a, int b, int c) {
    return c > 0 ? (a + b + 20) % 10 : (a - b + 20) % 10;
}

int go(int idx, int x, int y, int z, int d) {
    if (idx == n) return 0;
    int &ret = dp[idx][x][y][z][d];
    if (ret != -1) return ret;
    ret = 1e9;
    if ((from[idx] - '0' + x + 20) % 10 == to[idx] - '0')
        return ret = min(go(idx + 1, y, z, 0, !d), go(idx + 1, y, z, 0, d));


    for (int k = 1; k <= 3; k++) {
        ret = min(ret, go(idx, MOD(x, k, d), y, z, d) + 1);
        ret = min(ret, go(idx, MOD(x, k, d), MOD(y, k, d), z, d) + 1);
        ret = min(ret, go(idx, MOD(x, k, d), MOD(y, k, d), MOD(z, k, d), d) + 1);
    }
    return ret;
}

int main() {
    FIO;
    cin >> n;
    cin >> from >> to;
    memset(dp, -1, sizeof(dp));
    cout << min(go(0, 0, 0, 0, 0), go(0, 0, 0, 0, 1));
    return 0;
}

