#include <iostream>
#include <queue>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
struct node{
    int h,n,m,d;
};
queue <node> q;
int dir[6][3] = {{-1,0,0},{1,0,0},{0,-1,0},{0,0,-1},{0,1,0},{0,0,1}};
int arr[110][110][110], chk[110][110][110];
int N,M,H,state[3],ans=0;

int main(){
    FIO;
    cin>>M>>N>>H;
    for(int h=0;h<H;h++){
        for(int n=0;n<N;n++){
            for(int m=0;m<M;m++){
                cin>>arr[h][n][m];
                state[arr[h][n][m] + 1] += 1;
                if(arr[h][n][m] == 1 || arr[h][n][m] == -1) chk[h][n][m] = 1;
                if(arr[h][n][m] == 1) q.push({h,n,m,0});
            }
        }
    }
    
    if(state[1]==0){
        cout<<0;
        return 0;
    }
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        chk[cur.h][cur.n][cur.m] = 1;
        ans = max(ans,cur.d);
        
        for(int k=0;k<6;k++){
            int nh = cur.h + dir[k][0], nn = cur.n + dir[k][1], nm = cur.m +dir[k][2];
            if(0 <= nh && nh < H && 0 <= nn && nn < N && 0 <= nm && nm < M && arr[nh][nn][nm] == 0 && chk[nh][nn][nm] == 0){
                arr[nh][nn][nm] = chk[nh][nn][nm] = 1;
                ans = max(ans,cur.d+1);
                state[1] -= 1;
                q.push({nh,nn,nm,cur.d+1});
            }
        }
    }

    cout<<(state[1] != 0 ? -1 : ans);
    
    return 0;
}
