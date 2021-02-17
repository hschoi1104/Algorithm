//
//  main.cpp
//  boj
//
//  Created by seok on 2021/02/15.
//

#include <bits/stdc++.h>
using namespace std;
int arr[20][20],n,m,k;

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin>>n>>m>>k;
    int ny = k/m;
    if(k%m != 0)ny+=1;
    int nx = k-m*(ny-1);
    if(nx == 0) nx=m;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((i==1 && j!=1) || (i!=1 && j==1)) arr[i][j]=1;
            else arr[i][j] = arr[i-1][j]+arr[i][j-1];
        }
    }
    if(k == 0) cout<<arr[n][m]<<"\n";
    else{
        int tmp = arr[ny][nx];
        for(int i=ny;i<=n;i++){
            for(int j=nx;j<=m;j++){
                if(i == ny ||j == nx) arr[i][j]=1;
                else arr[i][j] = arr[i-1][j]+arr[i][j-1];
            }
        }
        cout<<tmp*arr[n][m]<<"\n";
    }
    return 0;
}

