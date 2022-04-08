#include<iostream>
#include<algorithm>
#include<queue>
#include<memory.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[21][21];
int N, time=0;
int x, y;
int visited[21][21];
int canEat[21][21];
int sz=2,cnt; 
int xx[4]={-1,0,1,0};
int yy[4]={0,1,0,-1};

void bfs(int x, int y,int s) {
	queue<pair<int,int>>q;
	q.push({x,y});
	visited[x][y]=1;
	while (!q.empty()) {
		x=q.front().first;
		y=q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx=x+xx[i], ty=y+yy[i];
			if (tx >= 0 && ty >= 0 && tx < N && ty < N ) {
				if (!visited[tx][ty]) {
					if (arr[tx][ty] < s) {
						if(arr[tx][ty])
							canEat[tx][ty]=1;
						visited[tx][ty]=visited[x][y]+1;
						q.push({tx,ty});
					}
					else if (arr[tx][ty] == s) {
						visited[tx][ty]= visited[x][y] + 1;
						q.push({tx,ty});
					}
				}
			}
		}
	}
}

int main(void) {
	fastio();
	cin >>N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j]==9) {
				x=i,y=j;
				arr[i][j]=0;
			}
		}
	}
	
	while (1) {
		memset(visited,0,sizeof(visited));
		memset(canEat,0,sizeof(visited));
		bfs(x,y,sz);
		int flag=0;
		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << canEat[i][j] << ' ';
			}
			cout << '\n';
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << visited[i][j] << ' ';
			}
			cout << '\n';
		}
		break;*/
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (canEat[i][j]) {
					flag=1;
					break;
				}
			}
			if(flag)
				break;
		}
		if(!flag)
			break;
		
		int MIN=1000;
		int tx, ty;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (canEat[i][j] && visited[i][j]) {
					MIN=min(MIN, visited[i][j]-1);
				}
			}
		}
		

		int f=0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(MIN==visited[i][j]-1&&canEat[i][j]){
					x=i, y=j;
					cnt++;
					arr[i][j]=0;
					f=1;
					break;
				}
			}
			if(f)
				break;
		}
		if (cnt == sz) {
			cnt=0;
			sz++;
		}
		time += MIN;
	}
	cout <<time <<'\n';
	return 0;

}