#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(), cout.tie();
using namespace std;

int dp[41], n, m, prv = 0, ans = 1, k;

int go(int x) {
    int &ret = dp[x];
    if (ret != -1) return ret;
    return ret = go(x - 1) + go(x - 2);
}

int main() {
    FIO;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for (int i = 0; i < m; i++) {
        cin >> k;
        ans *= go(k - prv - 1);
        prv = k;
    }
    ans *= go(n - prv);
    cout << ans;
    return 0;

}