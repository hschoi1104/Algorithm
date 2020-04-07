#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(), cout.tie();
#define MAX_NUM (double)(1e9+1)
using namespace std;
int n, ans, cnt[51];
vector<int> v;


int main() {
    FIO;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i < v.size(); i++) {
        double tmp = MAX_NUM, prv = -MAX_NUM;
        for (int j = i + 1; j < n; j++) {
            tmp = (double) (v[j] - v[i])/ (j - i);
            if (tmp > prv) {
                prv = tmp;
                cnt[j] += 1; cnt[i]+=1;
                ans = max(ans, max(cnt[j],cnt[i]));
            }
        }
    }
    cout << ans;
    return 0;
}