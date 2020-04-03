#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(), cout.tie();
using namespace std;
int arr[501][501], dist[2][501][501], dir[4][2] = {{0,  1},
                                                   {-1, 0},
                                                   {0,  -1},
                                                   {1,  0}};
bool chk[2][501][501];

struct node {
    int y, x, s, cnt;

    bool operator<(const node &tmp) const {
        return cnt > tmp.cnt;
    }
};

priority_queue<node, vector<node>> pq;
string s;
int n, t, r, c;

int go() {
    pq.push({0, 0, 0, 0});
    dist[0][0][0] = 0;
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (cur.y == r && cur.x == c) return cur.cnt;
        if (chk[cur.s][cur.y][cur.x]) continue;
        chk[cur.s][cur.y][cur.x] = true;

        for (int k = 0; k < 4; k++) {
            int ny = cur.y + dir[k][0], nx = cur.x + dir[k][1];
            if (0 <= ny && ny < n && 0 <= nx && nx < n && !chk[0][ny][nx] && dist[0][ny][nx] >= cur.cnt + 1) {
                dist[0][ny][nx] = cur.cnt + 1;
                pq.push({ny, nx, 0, dist[0][ny][nx]});
            }
        }

        for (int k = 0; k < 4; k++) {
            int ny = cur.y, nx = cur.x;
            bool find = false;
            while (!find) {
                ny += dir[k][0], nx += dir[k][1];
                if (!(0 <= ny && ny < n && 0 <= nx && nx < n)) break;
                if (arr[ny][nx]) find = true;
            }
            if (find && !chk[1][ny][nx] && dist[1][ny][nx] > (cur.s ? 0 : 1) * t + cur.cnt + 1) {
                dist[1][ny][nx] = cur.cnt + (cur.s ? 0 : 1) * t + 1;
                pq.push({ny, nx, 1, dist[1][ny][nx]});
            }
        }
    }
    return min(dist[0][r][c], dist[1][r][c]);
}

int main() {
    FIO;
    cin >> n >> t >> r >> c;
    r -= 1, c -= 1;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) arr[i][j] = (s[j] == '.' ? 0 : 1);
    }

    fill(dist[0][0], dist[1][500], 1e9);

    cout << go();
    return 0;
}