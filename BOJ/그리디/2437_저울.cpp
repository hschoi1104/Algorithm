#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(a, b) for(int i=a;i<b;i++)
using namespace std;
int n, x, sum, flag;
vector<int> v;

int main() {
    FIO;
    cin >> n;
    v.resize(n);
    FOR(0, n) cin >> v[i];

    sort(v.begin(), v.end());

    FOR(0, n) {
        if (v[i] <= sum + 1)sum += v[i];
        else {
            cout << sum + 1;
            flag = 1;
            break;
        }
    }
    if (!flag) cout << sum + 1;
    return 0;
}