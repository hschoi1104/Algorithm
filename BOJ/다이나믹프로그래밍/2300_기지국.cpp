#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false), cin.tie(),cout.tie();
using namespace std;
int n, dp[10002], y, x;
vector<pair<int, int>> v;

int main() {
    FIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({ x, abs(y) });
    }
    sort(v.begin(), v.end());
    fill(begin(dp), end(dp), INT_MAX);
    dp[0] = 0;
    dp[1] = v[0].second * 2;
    for (int i = 2; i <= n; i++) {
        int height = v[i - 1].second;
        for (int j = i - 1; j >= 0; j--) {
            height = max(height, v[j].second);
            dp[i] = min(dp[i], max(height * 2, v[i - 1].first - v[j].first) + dp[j]);
        }
    }
    cout << dp[n];
    return 0;
}

