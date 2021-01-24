//
//  main.cpp
//  boj
//
//  Created by seok on 2021/01/24.
//

#include <bits/stdc++.h>
using namespace std;
string s;
int a=INT_MAX,b=0;

int cal(string x){
    int res=0;
    for(auto it:x) res+=(it-'0')%2;
    return res;
}
void go(string tmp,int cnt){
    if(tmp.size()==1){
        a = min(a,cnt);
        b = max(b,cnt);
        return;
    }
    else if(tmp.size()>=3){
        for(int i=0;i<tmp.size()-2;i++){
            for(int j=i+1;j<tmp.size()-1;j++){
                int nxt = stoi(tmp.substr(0,i+1))+ stoi(tmp.substr(i+1,j-i))+stoi(tmp.substr(j+1));
                go(to_string(nxt),cnt+cal(to_string(nxt)));
            }
        }
    }
    else if(tmp.size()==2){
        int nxt = stoi(tmp.substr(0,1)) + stoi(tmp.substr(1));
        go(to_string(nxt),cnt+cal(to_string(nxt)));
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin>>s;
    go(s,cal(s));
    cout<<a<<" "<<b<<"\n";
    return 0;
}
