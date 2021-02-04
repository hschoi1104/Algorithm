#include <bits/stdc++.h>
using namespace std;
int dice[4][3],n,m,k,x,y,t,arr[21][21],dir[5][2]={{0,0},{0,1},{0,-1},{-1,0},{1,0}};
int go(int d){
    int tmp;
    if(d==1){
        tmp = dice[1][2];
        for(int i=2;i>0;i--) dice[1][i] = dice[1][i-1];
        dice[1][0]=tmp;
        swap(dice[3][1],dice[1][0]);
    }
    else if(d == 2){
        tmp = dice[1][0];
        for(int i=0;i<2;i++) dice[1][i] = dice[1][i+1];
        dice[1][2]=tmp;
        swap(dice[3][1],dice[1][2]);
    }
    else if(d == 3){
        tmp=dice[0][1];
        for(int i=0;i<3;i++) dice[i][1]=dice[i+1][1];
        dice[3][1]=tmp;
    }
    else if(d == 4){
        tmp=dice[3][1];
        for(int i=3;i>0;i--) dice[i][1]=dice[i-1][1];
        dice[0][1]=tmp;
    }
    if(arr[y][x] !=0){
        dice[3][1]=arr[y][x];
        arr[y][x]=0;
    }
    else if(arr[y][x] ==0) arr[y][x]=dice[3][1];
    
    return dice[1][1];
}
int main() {
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    cin>>n>>m>>y>>x>>k;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
    
    for(int i=0;i<k;i++){
        cin>>t;
        int ny = y+dir[t][0], nx = x+dir[t][1];
        if(0>ny || n<=ny || 0>nx || m<=nx) continue;
        y = ny; x = nx;
        cout<<go(t)<<"\n";
    }
    return 0;
}
