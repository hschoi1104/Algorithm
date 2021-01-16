//
//  main.cpp
//  boj
//
//  Created by seok on 2021/01/17.
//

#include <iostream>
#include <queue>
using namespace std;
int n,m,a,b,map[101];
struct node{
    int i,cnt;
};
queue<node>q;
int go(){
    q.push(node{1,0});
    while(!q.empty()){
        node cur = q.front();
        if(cur.i == 100) return cur.cnt;
        q.pop();
        int tmp=0;
        for(int p=cur.i;p<=cur.i+6 && p<=100;p++){
            if(map[p]==0) tmp = max(tmp,p);
            else q.push(node{map[p],cur.cnt+1});
        }
        q.push(node{tmp,cur.cnt+1});
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n+m;i++){
        cin>>a>>b;
        map[a]=b;
    }
    cout<<go()<<"\n";
    return 0;
}
