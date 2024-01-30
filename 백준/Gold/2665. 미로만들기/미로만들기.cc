#include<bits/stdc++.h>

using namespace std;

char arr[51][51];

int visited[51][51][2505];

int N;
int xx[4] ={0,1,0,-1};
int yy[4] ={1,0,-1,0};

void bfs(int x, int y, int cnt) {
	queue<tuple<int,int,int>>q;
	q.push({x,y,cnt});
	visited[x][y][cnt]=1;
	while (!q.empty()) {
		tie(x,y,cnt) = q.front();
		//cout << x <<' '<< y << ' '<<cnt << '\n';
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x+xx[i],ty=y+yy[i];
			if(tx<0||ty<0||tx>=N||ty>=N)
				continue;
			if (arr[tx][ty]=='0') {
				if (visited[tx][ty][cnt + 1]) { //벽을 바꿨는데도 방문한 곳이면
					continue;
				}
				if(cnt+1>N*N-2)
					continue;
				visited[tx][ty][cnt+1]=1;
				q.push({tx,ty,cnt+1});
			}
			else {
				if(visited[tx][ty][cnt]) //흰칸이고 방문했을 경우
					continue;
				visited[tx][ty][cnt]=1;
				q.push({tx,ty,cnt});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	bfs(0,0,0);
	
	for (int i = 0; i < N * N; i++) {
		if (visited[N - 1][N - 1][i]) {
			cout << i <<'\n';
			return 0;
		}
	}
	
}