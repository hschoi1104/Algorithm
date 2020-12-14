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
#include <string>
#include <climits>
#define FIO  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
struct node{
    int score;
    bool flag;
};
vector<string> names;
vector<queue<int>>votes(1010);
string t;
int chk[1001],score[1001];
int n;
int main(){
    FIO;
    cin>>n;
    getline(cin,t);
    for(int i=0;i<n;i++){
        getline(cin,t);
        names.push_back(t);
        chk[i]=score[i]=0;
    }
    int cnt=0,a;
    while(cin>>a){
        votes[cnt].push(a-1);
        for(int i=1;i<n;i++){
            cin>>a;
            votes[cnt].push(a-1);
        }
        cnt+=1;
    }
    while(1){
        //score 업데이트
        for(int i=0;i<cnt;i++){
            while(!votes[i].empty() && chk[votes[i].front()]==1) votes[i].pop();
            score[votes[i].front()]+=1;
        }
        
        //min,max
        int mn=INT_MAX,mx=0;
        for(int i=0;i<n;i++){
            if(chk[i]==0){
                mn = min(mn,score[i]);
                mx = max(mx,score[i]);
            }
        }
        
        //점수 과반이상
        if(mx*2>cnt || mx==mn){
            for(int i=0;i<n;i++){
                if(score[i]==mx) cout<<names[i]<<"\n";
            }
            return 0;
        }
        
        for(int i=0;i<n;i++){
            if(chk[i]==0 && score[i] == mn) chk[i]=1;
            score[i]=0;
        }
    }
    return 0;
}
