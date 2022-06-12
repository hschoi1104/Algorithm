#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, M, x, ans;
map<string,int>res;
int main() {
    FIO;
    cin>>N>>M;
    //멀티버스
    for(int i=0;i<N;i++){
        map<int,int>m;
        vector<int>v,sort_v;
        //행성
        for(int j=0;j<M;j++){
            cin>>x;
            v.push_back(x);
            sort_v.push_back(x);
        }
        sort(sort_v.begin(),sort_v.end());
        
        for(int j=0;j<M;j++) m[sort_v[j]]=j;
        
        //압축 압축-value
        string str;
        for(auto it: v) str+= to_string(m[it]);
        
        res[str] += 1;
    }
    //쌍 갯수
    for(auto it: res) ans+=(it.second*(it.second-1))/2;
    cout<<ans;
    return 0;
}
