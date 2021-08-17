//
//  main.cpp
//  boj
//
//  Created by seok on 2021/08/17.
//
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int n,x;
priority_queue<int> a;
priority_queue<int,vector<int>,greater<int>> b;
int main(){
    FIO;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        if(a.size() == b.size()) a.push(x);
        else b.push(x);
        
        if(b.size()>=1 && a.top()> b.top()){
            int tmp = a.top();
            a.pop();
            a.push(b.top());
            b.pop();
            b.push(tmp);
        }
        cout<<a.top()<<"\n";
    }
    return 0;
}
