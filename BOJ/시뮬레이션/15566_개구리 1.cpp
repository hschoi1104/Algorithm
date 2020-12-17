//
//  main.cpp
//  boj
//
//  Created by seok on 2020/12/17.
//

#include <iostream>
#include <vector>
#define FIO  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
int score[16][5],log_map[16][16],fav_flower[16][16],chk_flower_frog[16];
vector<vector<int>> flower;
int n,m,a,b,c;
bool flag=false,ans=false;
bool check_flower(int idx,int cur_flower){
    bool res = true;
    for(int i=0;i<flower[cur_flower].size();i++){
        int nxt = flower[cur_flower][i];
        if(chk_flower_frog[nxt]==0) continue;
        else{
            int topic = log_map[cur_flower][nxt];
            if(score[idx][topic]!=score[chk_flower_frog[nxt]][topic]) res = false;
        }
    }
    return res;
}
void go(int idx){
    if(idx==n+1){
        cout<<"YES\n";
        for(int i=1;i<=n;i++) cout<<chk_flower_frog[i]<<" ";
        cout<<"\n";
        ans = true;
        return;
    }
    for(int i=0;i<2;i++){
        int cur_flower = fav_flower[idx][i];
        if(cur_flower==-1)continue;
        if(chk_flower_frog[cur_flower]==0 && check_flower(idx,cur_flower)){
            chk_flower_frog[cur_flower]=idx;
            go(idx+1);
            if(ans)return;
            chk_flower_frog[cur_flower]=0;
        }
    }
    return;
}
int main(){
    FIO;
    cin>>n>>m;
    flower.resize(n+2);
    for(int i=1;i<=n;i++) for(int j=1;j<=4;j++) cin>>score[i][j];
    for(int i=1;i<=n;i++) {
        cin>>fav_flower[i][0]>>fav_flower[i][1];
        if(fav_flower[i][0] == fav_flower[i][1]) fav_flower[i][1]=-1;
    }
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        log_map[a][b]=log_map[b][a]=c;
        flower[a].push_back(b);
        flower[b].push_back(a);
    }
    go(1);
    if(!ans) cout<<"NO\n";
    return 0;
}
