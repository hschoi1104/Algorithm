//
//  main.cpp
//  boj
//
//  Created by seok on 2021/01/24.
//

#include <bits/stdc++.h>
using namespace std;

enum {E,W,S,N};
int n,m,r,ans,arr[110][110],state[110][110],dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

struct node{ int y,x,d; };
queue<node>q;

int change(char c){
    if(c=='E') return 0;
    else if(c=='W') return 1;
    else if(c=='S') return 2;
    else return 3;
}

void go(int y,int x,int d){
    q.push(node{y,x});
    while(!q.empty()){
        node cur = q.front();
        q.pop();
        int ny = cur.y,nx = cur.x;
        for(int i=0;i<arr[cur.y][cur.x];i++){
            if(1>ny || ny>n || 1>nx || nx>m) continue;
            if(state[ny][nx]==0){
                q.push(node{ny,nx});
                state[ny][nx]=1;
                ans+=1;
            }
            ny+=dir[d][0];
            nx+=dir[d][1];
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    
    cin>>n>>m>>r;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>arr[i][j];
    for(int i=0;i<r;i++){
        int a,b,d,e;
        char c;
        cin>>a>>b>>c>>d>>e;
        go(a,b,change(c));
        state[d][e]=0;
    }
    cout<<ans<<"\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<(state[i][j]==0?"S ":"F ");
        }
        cout<<"\n";
    }
    return 0;
}
