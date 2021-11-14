#include <iostream>
#include <vector>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
vector<vector<int>>g;
int n, chk[30][30],dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
double per[4];
double dfs(int y,int x,int dep){
    double ans = 0.0;
    if(dep == n) return 1.0;
    chk[y][x]=1;
    for(int k=0;k<4;k++){
        int ny = y + dir[k][0], nx = x+ dir[k][1];
        if(!chk[ny][nx]) ans += (per[k] * dfs(ny,nx,dep+1));
    }
    chk[y][x]=0;
    return ans;
}
int main(){
    FIO;
    cin>>n;
    for(int i=0;i<4;i++) {
        cin>>per[i];
        per[i]/=100.0;
    }
    g.resize(n+1);
    cout.precision(10);
    cout<< fixed<< dfs(15,15,0);
    
    return 0;
}
