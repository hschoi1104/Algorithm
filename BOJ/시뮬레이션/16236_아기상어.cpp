#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>
#define FIO ios_base::sync_with_stdio(NULL);cin.tie(NULL);
using namespace std;
struct pos{int y,x;};
int n,m,g[30][30],chk[30][30],ate,ssize=2,fish,turn,dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
pos shark;
queue<pos> q;
int age(){
    if(ate == ssize){
        ate = 0;
        ssize += 1;
    }
    return (ssize<2 ? 2:ssize);
}
void search(){
    int dist = 1e9;
    memset(chk,0,sizeof(chk));
    q.push(shark);
    chk[shark.y][shark.x] = 1;
    while(!q.empty()){
        auto cur = q.front();
        if(g[cur.y][cur.x] && age()>g[cur.y][cur.x]) dist = min(dist,chk[cur.y][cur.x]);
        q.pop();
        for(int k=0;k<4;k++){
            int ny = cur.y + dir[k][0], nx = cur.x + dir[k][1];
            if(0 > ny || n <= ny || 0 > nx || n <= nx || chk[ny][nx] || age()<g[ny][nx]) continue;
            chk[ny][nx] = chk[cur.y][cur.x] + 1;
            q.push({ny,nx});
        }
    }

    //최대 높이 체크
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(chk[i][j] == dist && g[i][j] && g[i][j]<age()){
                shark = {i,j};
                g[i][j] = 0;
                fish -= 1;
                ate += 1;
                turn += chk[i][j]-1;
                return;
            }
        }
    }
    return;
}

int main(){
    FIO;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
            if(g[i][j] == 9){
                shark = pos{i,j};
                g[i][j] = 0;
            }
            if(g[i][j] != 0 && g[i][j] != 9) fish += 1;
        }
    }
    while(fish){
        int prv_fish = fish;
        search();
        if(fish == prv_fish) break;
    }
    cout<<(!turn ? 0:turn);
    return 0;
}
