//
//  main.cpp
//  boj
//
//  Created by seok on 2020/12/10.
//

#include <iostream>
#include <string>
#include <queue>
#define FIO  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
int M,N,tmp[1401],a,b,c;

int main(){
    FIO;
    cin>>M>>N;
    
    for(int i=0;i<N;i++){
        cin>>a>>b>>c;
        for(int j=a;j<a+b;j++) tmp[j]+=1;
        for(int j=a+b;j<2*M-1;j++) tmp[j]+=2;
    }
  
    for(int y=0;y<M;y++){
        for(int x=0;x<M;x++){
            if(x == 0) cout<<tmp[M-y-1]+1<<" ";
            else cout<<tmp[M+x-1]+1<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
