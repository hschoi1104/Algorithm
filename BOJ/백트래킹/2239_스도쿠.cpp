//
//  main.cpp
//  boj
//
//  Created by seok on 2021/01/17.
//

#include <iostream>
#include <vector>
using namespace std;

int map[10][10];
struct node{
    int y,x;
};
vector<node>v;
void go(int idx){
    if(idx == v.size()){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++) cout<<map[i][j];
            cout<<"\n";
        }
        exit(0);
        return;
    }
    int chk[11];
    for(int i=0;i<=10;i++) chk[i]=0;
    node cur = v[idx];
    //가로,세로 체크
    for(int i=0;i<9;i++) chk[map[cur.y][i]]=chk[map[i][cur.x]]=1;
    //3x3체크
    int ny = cur.y/3*3, nx = cur.x/3*3;
    for(int i=ny;i<ny+3;i++) for(int j= nx; j<nx+3;j++) chk[map[i][j]]=1;
    
    //재귀
    for(int i=1;i<10;i++){
        if(chk[i]==0){
            map[cur.y][cur.x]=i;
            go(idx+1);
            map[cur.y][cur.x]=0;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    for(int i=0;i<9;i++){
        string input; cin>>input;
        for(int j=0;j<9;j++){
            map[i][j] = input[j]-'0';
            if(map[i][j] == 0) v.push_back(node{i,j});
        }
    }
    
    go(0);
    return 0;
}
