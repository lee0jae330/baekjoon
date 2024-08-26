#include<bits/stdc++.h>

using namespace std;

int N,M,k;
int arr[21][21];
pair<int,int>smell[21][21]; //번호 시간

int xx[4]={-1,1,0,0};
int yy[4]={0,0,-1,1};


class shark{
    public:
        int num; //번호
        int dir;//방향
        int priority_dir[4][4]; // 우선순위
        int x,y; //현재 좌표
        int isAlive=1;
    public:
        shark(){
            
        }
        shark(int num, int x, int y){
            this->num=num;
            this->x=x;
            this->y=y;
        }
        void setDir(int d){
            this->dir=d;
        }
        void setPriority(){
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    cin >> this->priority_dir[i][j];
                }
            }
        }
};

shark s[401];

void move(){
    int cnt=0;
    while(1){
        int num=0;
        if(cnt>1000){
            cout <<-1;
            return;
        }
        for(int idx=1;idx<=M;idx++){
            if(s[idx].isAlive)
                num++;
            if(num>=2)
                break;
        }
        if(num==1){
            cout << cnt;
            return;
        }
        for(int idx=1;idx<=M;idx++){
            shark tmp = s[idx];
            if(!tmp.isAlive) //해당 상어가 보드에 없을 경우
                continue;
            int n = tmp.num;
            int d = tmp.dir;
            int x = tmp.x, y=tmp.y; //현재 좌표
            //인접한 칸을 검사
            int flag=0;
        
            for(int i=0;i<4;i++){
                int next_dir = tmp.priority_dir[d-1][i];
                int tx = x+xx[next_dir-1],ty=y+yy[next_dir-1];
                if(tx<0||ty<0||tx>=N||ty>=N) //이동 불가한 곳
                    continue;
                if(!smell[tx][ty].first){
                    //아무 냄새도 없는 칸을 찾은 경우
                    flag=1;
                    if(!arr[tx][ty]){
                        //아무 상어도 없는 경우
                        arr[tx][ty]=n; //이동
                        arr[x][y]=0; //이동 전 칸 비워주기
                        s[idx].x=tx,s[idx].y=ty;
                        s[idx].dir=next_dir; //방향 바꾸기
                        
                    }   
                    else{
                        //상어가 있는 경우 무조건 번호가 작은 상어기 때문에 아웃
                        s[idx].isAlive = 0;
                        arr[x][y]=0;
                    }
                    break;
                }
            }
            if(!flag){
                //아무 냄새도 없는 칸을 찾지 못한 경우
                for(int i=0;i<4;i++){
                    int next_dir = tmp.priority_dir[d-1][i];
                    int tx = x+xx[next_dir-1],ty=y+yy[next_dir-1];
                    if(tx<0||ty<0||tx>=N||ty>=N) //이동 불가한 곳
                        continue;
                    if(smell[tx][ty].first==n){
                        //자신의 냄새가 있는 곳을 찾은 경우
                        arr[tx][ty]=n; //이동
                        arr[x][y]=0; //이동 전 칸 비워주기
                        s[idx].x=tx,s[idx].y=ty;
                        s[idx].dir=next_dir; //방향 바꾸기
                        break;
                    }
                }
            }
        }
        //냄새 1초씩 줄이기
        
        
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(smell[i][j].first){
                    smell[i][j].second--;
                    if(smell[i][j].second<=0)
                        smell[i][j]={0,0};
                }
            }
        }
        
        for(int idx=1;idx<=M;idx++){
            if(s[idx].isAlive){
                int x = s[idx].x,y=s[idx].y;
                smell[x][y]={s[idx].num,k};
            }
        }
        cnt++;
        
    }
       
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> k;
    //냄새 배열을 0,0으로 초기화
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            smell[i][j]={0,0};
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
            if(arr[i][j]){
                s[arr[i][j]]=shark(arr[i][j],i,j);
                smell[i][j].first = arr[i][j];
                smell[i][j].second = k;
            }
        }
    }
    
    for(int i=1;i<=M;i++){
        int d;
        cin >> d;
        s[i].setDir(d);
    }
    for(int i=1;i<=M;i++){
        s[i].setPriority();
    }
    move();
    return 0;
    
    
}