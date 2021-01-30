//
//  main.cpp
//  boj
//
//  Created by seok on 2021/01/26.
//

#include <bits/stdc++.h>
using namespace std;
int n,m,k,d[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
char arr[12][12];
string god;
unordered_map<string, int> um;
int go(int idx,int y,int x){
    int ans=0;
    if(idx==0){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(arr[i][j] == god[0]) ans += go(1,i,j);
            }
        }
    }
    else if(idx == god.size()) return 1;
    else{
        for(int i=0;i<8;i++){
            int ny = y+d[i][0], nx = x+d[i][1];
            if(ny == 0) ny=n;
            if(ny == n+1) ny=1;
            if(nx == 0) nx=m;
            if(nx == m+1) nx=1;
            if(arr[ny][nx]==god[idx]) ans += go(idx+1,ny,nx);
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    
    cin>>n>>m>>k;
    
    for(int i=1;i<=n;i++){
        string tmp; cin>>tmp;
        for(int j=0;j<tmp.size();j++){
            arr[i][j+1]=tmp[j];
        }
    }
    for(int i=0;i<k;i++){
        cin>>god;
        auto e = um.find(god);
        if(e!=um.end()) cout<< um[god] <<"\n";
        else{
            int res = go(0,1,1);
            um[god]=res;
            cout<<res<<"\n";
        }
    }
    
    return 0;
}
