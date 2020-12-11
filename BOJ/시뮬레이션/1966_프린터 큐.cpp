//
//  main.cpp
//  boj
//
//  Created by seok on 2020/12/12.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#define FIO  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
int t,N,M,x;
struct node{
    int val;
    bool mark;
};
queue<node>q;
multiset<int>s;

void init(){
    while(!q.empty()) q.pop();
    s.clear();
    return;
}

int main(){
    FIO;
    cin>>t;
    while(t--){
        init();
        cin>>N>>M;
        for(int i=0;i<N;i++){
            cin>>x;
            s.insert(-x);
            node tmp = {x,false};
            if(i == M) tmp.mark=true;
            q.push(tmp);
        }
        int cnt =0;
        while(!q.empty()){
            
            node cur = q.front();
            if(*(s.begin()) == -cur.val){
                cnt+=1;
                s.erase(s.begin());
                if(cur.mark){
                    cout<<cnt<<"\n";
                    break;
                }
            }
            else q.push(cur);
            q.pop();
        }
    }
    return 0;
}
