#include <bits/stdc++.h>

#define MOD 9901
#define FIO ios_base::sync_with_stdio(false), cin.tie(),cout.tie();
using namespace std;

int n, dp[100001][3];

int main() {
    FIO;
    cin >> n;
    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    for (int i = 0; i < n - 1; i++) {
        dp[i + 1][0] = (dp[i][1] + dp[i][2]) % MOD;
        dp[i + 1][1] = (dp[i][0] + dp[i][2]) % MOD;
        dp[i + 1][2] = (dp[i][0] + dp[i][1] + dp[i][2]) % MOD;
    }
    cout << (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) % MOD;
    return 0;
}
