#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll s,x,m;
int main() {
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    cin>>m;
    while(m--){
        string op; int i;
        cin>>op;
        if(op != "all" && op!="empty"){
            cin>>i;
            x = 1<<i;
        }
        
        if(op == "add"){ if(!(s&(1<<i))) s |=(1<<i);}
        else if(op == "remove"){ if(s&(1<<i)) s&= ~(1<<i);}
        else if(op == "check") cout<<(s&(1<<i) ? "1\n":"0\n");
        else if(op == "toggle"){
            if(s&(1<<i)) s&= ~(1<<i);
            else s|=(1<<i);
        }
        else if(op == "all") s=2097150;
        else if(op == "empty") s=0;
    }
    return 0;
}
