#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(a, b) for(int i=a;i<b;i++)
using namespace std;
int n, l;
vector<int> v;

int main() {
    FIO;
    cin >> n >> l;
    v.resize(n);
    FOR(0, n) cin >> v[i];

    sort(v.begin(), v.end());

    int prv = v[0], cnt = 1;
    FOR(0, v.size()) {
        if (v[i] - prv > l - 1) {
            cnt += 1;
            prv = v[i];
        }
    }
    cout << cnt;
    return 0;
}