#include<bits/stdc++.h>

using namespace std;

int N,M,P,flag;
char arr[1001][1001];
int visited[1001][1001];
int castle[10][1001][1001];
long long S[10];
int sol[10];
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};

queue<pair<int,int>>q[10];



void bfs(int n, int mx){
    queue<pair<int,int>>tmp;
    while(!q[n].empty()){
        auto [x,y]=q[n].front();
        
        q[n].pop();
        for(int i=0;i<4;i++){
            int tx=x+xx[i],ty=y+yy[i];
            
            if(tx<0||ty<0||tx>=N||ty>=M||castle[n][tx][ty]!=-1||visited[tx][ty])
                continue;
            
            if(arr[tx][ty]=='.'){
                if(castle[n][x][y]+1>mx){
                    tmp.push({x,y});
                }
                else{
                    castle[n][tx][ty]=castle[n][x][y]+1;
                    q[n].push({tx,ty});
                    sol[n]++;
                    visited[tx][ty]=1;
                    flag=0;
                }
            }
        }
    }
    q[n]=tmp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> P;
    for(int i=1;i<=P;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++)
                castle[i][j][k]=-1;
        }
    }
    
    for(int i=1;i<=P;i++)
        cin >> S[i];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >>arr[i][j];
            if(arr[i][j]>='1'&&arr[i][j]<='9'){
                int p = arr[i][j]-'0';
                q[p].push({i,j});
                castle[p][i][j]=0;
                visited[i][j]=1;
                sol[p]++;
            }
            
        }
    }
    int turn=1;
    while(1){
        if(flag)
            break;
        flag=1;
        for(int p=1;p<=P;p++){
            bfs(p,turn*S[p]);
        }
        turn++;
    }
    for(int i=1;i<=P;i++)
        cout << sol[i]<<' ';
    return 0;
}