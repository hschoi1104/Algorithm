#include <bits/stdc++.h>
using namespace std;
int n,d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char arr[7][7];
struct node{
    int y,x;
};
vector<node>v;
bool chk(){
    for(int k=0;k<4;k++){
        for(auto it:v){
            int ny = it.y+d[k][0], nx = it.x+d[k][1];
            while(0<=ny && ny<n && 0<=nx && nx<n && arr[ny][nx]!='O' && arr[ny][nx]!='T'){
                if(arr[ny][nx]=='S') return false;
                ny+=d[k][0], nx+=d[k][1];
            }
        }
    }
    return true;
}
void go(int idx,int dep){
    if(dep == 3){
        if(chk()){
            cout<<"YES\n";
            exit(0);
        }
        else return;
    }
    for(int i=idx;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!='X') continue;
            arr[i][j]='O';
            go(i,dep+1);
            arr[i][j]='X';
        }
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    cin>>n;
    
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        cin>>arr[i][j];
        if(arr[i][j]=='T') v.push_back(node{i,j});
    }
    
    go(0,0);
    cout<<"NO\n";
    return 0;
}
