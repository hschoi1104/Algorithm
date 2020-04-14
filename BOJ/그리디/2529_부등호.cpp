#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(a, b) for(int i=a;i<b;i++)
using namespace std;
vector<string> v;
vector<int> ans;
int n;

int main() {
    FIO;
    cin >> n;
    FOR(0, n) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    FOR(0, n + 1) ans.push_back(9 - i);
    //최대
    do {
        bool flag = true;
        FOR(0, v.size()) {
            if (v[i][0] == '<' && !(ans[i] < ans[i + 1]) || v[i][0] == '>' && !(ans[i] > ans[i + 1])) {
                flag = false;
                break;
            }
        }
        if (!flag) continue;
        else break;

    } while (prev_permutation(ans.begin(), ans.end()));

    FOR(0, n + 1) cout << ans[i];
    cout << "\n";
    ans.clear();
    FOR(0, n + 1) ans.push_back(i);
    //최소
    do {
        bool flag = true;
        FOR(0, v.size()) {
            if (v[i][0] == '<' && !(ans[i] < ans[i + 1]) || v[i][0] == '>' && !(ans[i] > ans[i + 1])) {
                flag = false;
                break;
            }
        }
        if (!flag) continue;
        else break;
    } while (next_permutation(ans.begin(), ans.end()));
    FOR(0, n + 1) cout << ans[i];


    return 0;
}