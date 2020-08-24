//
//  main.cpp
//  11084_나이트의 염탐
//
//  Created by seok on 2020/08/24.
//  Copyright © 2020 seok. All rights reserved.
//

#include <iostream>
#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MOD 1000000009
#define MAX 1000000000
typedef long long ll;
using namespace std;
ll dist[410][410],cnt[410][410];
int dy[8]={-2,-1,1,2,2,1,-1,-2},dx[8]={1,2,2,1,-1,-2,-2,-1},r,c;
struct node{
    int y,x;
};
queue<node>q;
void bfs(){
    dist[1][1]=0; cnt[1][1]=1;
    q.push(node{1,1});
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int k=0;k<8;k++){
            int ny = cur.y+dy[k],nx = cur.x+dx[k];
            if(0<ny && ny<=r && 0<nx && nx<=c){
                if(dist[ny][nx]> dist[cur.y][cur.x]+1){
                    dist[ny][nx] = dist[cur.y][cur.x]+1;
                    cnt[ny][nx] = cnt[cur.y][cur.x];
                    q.push(node{ny,nx});
                }
                else if(dist[ny][nx]==dist[cur.y][cur.x]+1){
                    cnt[ny][nx]+=cnt[cur.y][cur.x];
                    cnt[ny][nx]%=MOD;
                }
            }
        }
    }
    return;
}
int main() {
    FIO;
    cin>>r>>c;
    fill(&dist[0][0],&dist[405][405],MAX);
    bfs();
    if(dist[r][c]==MAX) cout<<"None";
    else cout<<dist[r][c]<<" "<<cnt[r][c];
    return 0;
}
