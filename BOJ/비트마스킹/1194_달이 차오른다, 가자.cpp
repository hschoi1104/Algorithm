#include <bits/stdc++.h>
using namespace std;

int n,m,chk[51][51][1<<7],sy,sx,d[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
char arr[51][51];
struct node{
    int y,x,bit,cnt;
};
queue<node>q;
int go(){
    q.push(node{sy,sx,0,0});
    while(!q.empty()){
        node cur = q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int ny = cur.y+d[k][0], nx = cur.x+d[k][1];
            if(0<=ny && ny<n && 0<=nx && nx<m && arr[ny][nx]!='#'){
                char nVal = arr[ny][nx];
                if(nVal=='1'){
                    return cur.cnt+1;
                }
                else if('a'<= nVal && nVal<='f'){
                    int nBit = cur.bit | 1<<(nVal-'a');
                    if(chk[ny][nx][nBit]==0){
                        chk[ny][nx][nBit]=1;
                        q.push(node{ny,nx,nBit,cur.cnt+1});
                    }
                }
                else if('A'<= nVal && nVal<='F'){
                    if(cur.bit & 1<<(nVal-'A') && chk[ny][nx][cur.bit]==0){
                        chk[ny][nx][cur.bit]=1;
                        q.push(node{ny,nx,cur.bit,cur.cnt+1});
                    }
                }
                else if(chk[ny][nx][cur.bit]==0){
                    chk[ny][nx][cur.bit]=1;
                    q.push(node{ny,nx,cur.bit,cur.cnt+1});
                }
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j] == '0') sy=i,sx=j;
        }
    }
    cout<<go()<<"\n";
    return 0;
}
