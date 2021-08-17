//
//  main.cpp
//  boj
//
//  Created by seok on 2021/02/15.
//

#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int a,s;
};
vector<int>v;
int n,m,p[100010],sol[100010],a,b,c;
node find(int a){
    if(p[a]==a) return node{a,sol[a]};
    node res = find(p[a]);
    res.s+=sol[a];
    sol[a]=0;
    p[a]=res.a;
    return res;
}
void uni(int a,int b){
    node aa = find(a);
    node bb = find(b);
    if(aa.a!=bb.a){
        if(aa.s>bb.s){
            p[bb.a]=aa.a;
            sol[aa.a]-=bb.s;
            sol[bb.a]=0;
        }
        else if(aa.s<bb.s){
            p[aa.a]=bb.a;
            sol[bb.a]-=aa.s;
            sol[aa.a]=0;
        }
        else p[aa.a]=p[bb.a]=sol[aa.a]=sol[bb.a]=0;
    }
    return;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        p[i]=i;
        cin>>sol[i];
    }
    while(m--){
        cin>>a>>b>>c;
        if(a==1){
            node bb = find(b);
            node cc = find(c);
            p[cc.a]=bb.a;
            sol[bb.a]+=sol[cc.a];
            sol[cc.a]=0;
        }
        else uni(b,c);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        node res = find(i);
        if(res.a == i) {
            cnt+=1;
            v.push_back(res.s);
        }
    }
    cout<<cnt<<"\n";
    sort(v.begin(),v.end());
    for(auto it:v) cout<<it<<" ";
    return 0;
}

