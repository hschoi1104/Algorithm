//
//  main.cpp
//  boj
//
//  Created by seok on 2020/12/10.
//

#include <iostream>
#define FIO  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
int M,N,tmp[1401],a,b,c;

int main(){
    FIO;
    cin>>M>>N;
    
    for(int i=0;i<N;i++){
        cin>>a>>b>>c;
        for(int j=a;j<2*M-1;j++) tmp[j] += (j<a+b ? 1:2);
    }
    
    for(int y=0;y<M;y++){
        for(int x=0;x<M;x++) cout<<(x==0 ? tmp[M-y-1] : tmp[M+x-1])+1<<" ";
        cout<<"\n";
    }
    return 0;
}
