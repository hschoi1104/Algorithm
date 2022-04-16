#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n,s,x,h;
long long ans;
vector<int>v;
map<int,int>m;

void goLeft(int idx, int sum){
    if(idx == h){
        m[sum]+=1;
        return;
    }
    goLeft(idx+1, sum);
    goLeft(idx+1, sum+v[idx]);
    return;
}
void goRight(int idx, int sum){
    if(idx == n){
        ans += m[s-sum];
        return;
    }
    goRight(idx+1, sum);
    goRight(idx+1, sum+v[idx]);
    return;
}
int main(){
    FIO;
    cin>>n>>s;
    h = n/2;
    v.resize(n);
    for(int i=0;i<n;i++) cin>>v[i];
    goLeft(0,0);
    goRight(h,0);
    if(s==0) ans--;
    cout<<ans;
    return 0;
}
