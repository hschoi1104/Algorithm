#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(a, b) for(int i=a;i<b;i++)
using namespace std;
vector<int> v, ans;
int n, x;

int main() {
    FIO;
    cin >> n;
    FOR(0, n) {
        cin >> x;
        v.push_back(x);
    }
    FOR(1, n + 1) ans.push_back(i);
    do {
        bool flag = true;
        FOR(0, n) {
            int cnt = 0;
            for (int j = i - 1; j >= 0; j--) if (ans[i] < ans[j]) cnt += 1;
            if (cnt != v[ans[i] - 1]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            FOR(0, ans.size()) cout << ans[i] << " ";
            break;
        }
    } while (next_permutation(ans.begin(), ans.end()));
    return 0;
}