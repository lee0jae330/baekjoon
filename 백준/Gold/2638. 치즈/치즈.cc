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

int cheese[101][101];
int side[101][101];
int visited[101][101];
int N, M;
int xx[4]={-1,0,1,0};
int yy[4]={0,1,0,-1};

vector<pair<int,int>>v;

void bfs(int x, int y) {
	queue<pair<int,int>>q;
	q.push({x,y});
	visited[x][y]=1;
	while (!q.empty()) {
		x= q.front().first;
		y=q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx=x+xx[i], ty=y+yy[i];
			if (tx >= 0 && ty >= 0 && tx < N && ty < M) {
				if (!cheese[tx][ty]) {
					side[x][y]++;
				}
				else {
					if (cheese[tx][ty] && !visited[tx][ty]) {
						visited[tx][ty]=1;
						q.push({tx,ty});
					}
				}
			
			}
		}
	}
}

void isInside(int x, int y) {
	queue<pair<int,int>>q;
	q.push({x,y});
	visited[x][y]=1;
	int flag=0;
	while (!q.empty()) {
		x=q.front().first;
		y=q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx=x+xx[i], ty=y+yy[i];
			if (tx >= 0 && ty >= 0 && tx < N && ty < M) {
				if (cheese[tx][ty]) {
					v.push_back({tx,ty});
				}
				else {
					if (!visited[tx][ty]) {
						visited[tx][ty]=1;
						q.push({tx,ty});
					}
				}
			}
			//치즈로 둘러싸인 공간 x
			else{
				flag=1;
			}	
		}
	}
	if (!flag) {
		for (int i = 0; i < v.size(); i++) {
			side[v[i].first][v[i].second]--;
		}
	}
	
	v.clear();
}

int main(void) {
	fastio();
	cin >>N>>M;
	for (int i = 0; i < N; i++) {
		for(int j=0;j<M;j++)
			cin>>cheese[i][j];
	}
	int time=0;
	while (1) {
		int flag=0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (cheese[i][j]) {
					flag=1;
					break;
				}
			}
			if(flag)
				break;
		}
		if(!flag)
			break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (cheese[i][j] && !visited[i][j]) {
					bfs(i, j);
				}
			}
		}


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!cheese[i][j] && !visited[i][j]) {
					isInside(i,j);

				}
			}
		}
		

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (side[i][j]>=2) {
					cheese[i][j]=0;
				}
			}
		}
		time++;
		
		memset(side,0,sizeof(side));
		memset(visited,0,sizeof(visited));
	}
	cout << time <<'\n';
	return 0;
}