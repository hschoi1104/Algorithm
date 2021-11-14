#include <iostream>
#include <queue>
#define FIO ios_base::sync_with_stdio(NULL);cin.tie(NULL);
using namespace std;
int n,m,x,map[10][10],chk[10][10],day,dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}},cheese;
queue<pair<int,int>> q;
bool count(int y,int x){
    int cnt = 0;
    for(int k=0;k<4;k++) {
        if(map[y+dir[k][0]][x+dir[k][1]]==1) cnt+=1;
        if(cnt>=2) break;
    }
    return (cnt==2 ? true:false);
}
void flow(){
    memset(chk,0,sizeof(chk));
    q.push({0,0});
    map[0][0] = 1;
    while(!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        chk[y][x] = 1;
        for(int k=0;k<4;k++){
            int dy = y + dir[k][0], dx = x + dir[k][1];
            if(0 > dy || dy >= n || 0 > dx || dx >= m || chk[dy][dx] || map[dy][dx] == 2) continue;
            chk[dy][dx] = map[dy][dx] = 1;
            q.push({dy,dx});
        }
    }
    return;
}
void melt(){
    memset(chk,0,sizeof(chk));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j] != 2) continue;
            if(count(i,j)){
                map[i][j] = 0;
                cheese -= 1;
            }
        }
    }
    return;
}

int main(){
    FIO;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>x;
            if(x) {
                map[i][j] = 2;
                cheese += 1;
            }
        }
    }
    while(cheese){
        day+=1;
        flow();
        melt();
    }
    cout<<day;
    return 0;
}
