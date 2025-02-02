#include<iostream>

#include<queue>

using namespace std;

void fastio(){

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);

}

int N,M,K;

int arr[101][101];

int visited[101][101];

int xx[4]={0,1,0,-1};

int yy[4]={1,0,-1,0};

bool canFarm =false;

int bfs(int x, int y){

    queue<pair<int,int>>q;

    visited[x][y]=1;

    q.push({x,y});

    int cnt=0;

    while(!q.empty()){

        x=q.front().first;

        y=q.front().second;

        cnt++;

        q.pop();

        for(int i=0;i<4;i++){

            int tx =x+xx[i], ty=y+yy[i];

            if(tx>=0&&ty>=0&&tx<N&&ty<N&&!arr[tx][ty]&&!visited[tx][ty]){

                q.push({tx,ty});

                visited[tx][ty]=1;

            }

            

        }

    }

    return cnt;

}

int main()

{

    fastio();

    cin >> N>>M>>K;

    for(int i=0;i<N;i++){

        for(int j=0;j<N;j++)

            cin >> arr[i][j];

    }

    for(int i=0;i<N;i++){

        for(int j=0;j<N;j++){

            if(!arr[i][j]&&!visited[i][j]){

                int tmp =bfs(i,j);

                int need = tmp /K;

                if(tmp%K)

                    need++;

                M-=need;

                canFarm=true;

            }

        }

    }

    if(M>=0&&canFarm){

        cout << "POSSIBLE"<<'\n'<<M;

    }

    else 

        cout  << "IMPOSSIBLE";

    return 0;

}

