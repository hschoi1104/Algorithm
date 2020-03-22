#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0), cin.tie(), cout.tie();
using namespace std;
int chk[20001];

queue<pair<int, string>>q;

string bfs(int x) {
    q.push({ 1,"1" });
    chk[1] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur.first == 0) return cur.second;
        for (int k = 0; k <= 1; k++) {
            int tmp = (cur.first * 10 + k) % x;

            if (!chk[tmp]) {
                chk[tmp] = 1;
                if (k == 0) q.push({ tmp,cur.second + "0" });
                else q.push({ tmp,cur.second + "1" });
            }
        }
    }
    return "BRAK";
}
int main() {
    FIO;
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        memset(chk, 0, sizeof(chk));
        cout << bfs(n) << "\n";
        while (!q.empty()) q.pop();
    }
    return 0;
}