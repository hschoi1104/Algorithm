#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0), cin.tie(), cout.tie();
using namespace std;
typedef long long ll;
ll combi[30][21], dp[30][2], n, t;

ll getCombi(ll n, ll r) {
    if(n<r || n<=0) return 0;
    if (r == 1) return n;
    if (r == 0) return 1;
    if (r > n / 2) r = n - r;
    ll& ret = combi[n][r];
    if (ret != -1) return ret;
    return ret = getCombi(n - 1, r) + getCombi(n - 1, r - 1);
}

int main() {
    FIO;
    for(int i=0;i<20;i++)memset(combi[i], -1, sizeof(combi[i]));
    cin >> t;
    dp[1][0] = dp[2][0] = dp[2][1] = dp[0][0] = dp[0][1] = 1;
    for (ll i = 3; i <= 20; i++) {
        for (ll k = 1; k <= i; k++) {
            if (i % 2 == 0) {
                if (k % 2 == 0) dp[i][0] += dp[k - 1][0] * dp[i - k][0] * getCombi(i - 1, k - 1);
                else dp[i][1] += dp[k - 1][1] * dp[i - k][0] * getCombi(i - 1, k - 1);
            }
            else {
                if (k % 2 == 0) dp[i][0] += dp[k - 1][0] * dp[i - k][0] * getCombi(i - 1, k - 1);
                else dp[i][1] += dp[k - 1][0] * dp[i - k][0] * getCombi(i - 1, k - 1);
            }
        }
    }
    while (t--) {
        cin >> n; cout << dp[n][0] + dp[n][1] << "\n";
    }

    return 0;
}