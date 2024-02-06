#include<bits/stdc++.h>

using namespace std;

int visited[2][51];
char arr[2][51];

int M;

int xx[4] ={0,1,0,-1};
int yy[4] ={1,0,-1,0};

void bfs(int x, int y) {
	queue<pair<int,int>>q;
	q.push({x,y});
	visited[x][y] =1;
	while (!q.empty()) {
		tie(x,y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x+xx[i],ty=y+yy[i];
			if (tx < 0 || ty < 0 || tx >= 2 || ty >= M||visited[tx][ty]) {
				continue;
			}
			if (arr[tx][ty] == '.') {
				visited[tx][ty] = visited[x][y] +1;
				q.push({tx,ty});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> M;
	
	int cnt =0;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if(arr[i][j] =='.')
				cnt++;
		}
	}

	int sol = 1e9;
	
	if (arr[0][0] == '.') {
		bfs(0,0);
		if (arr[0][M - 1] == '.') {
			sol = min(sol, visited[0][M-1]);
		}
		if (arr[1][M - 1] == '.') {
			sol = min(sol, visited[1][M-1]);
		}
	}

	memset(visited,0,sizeof(visited));
	
	if (arr[1][0] == '.') {
		bfs(1,0);
		if (arr[0][M - 1] == '.') {
			sol = min(sol,visited[0][M-1]);
		}
		if (arr[1][M - 1] == '.') {
			sol = min(sol, visited[1][M-1]);
		}
	}

	cout << cnt - sol <<'\n';
}