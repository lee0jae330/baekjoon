#include<bits/stdc++.h>

using namespace std;

int N, M;

int arr[51][51];
int visited[51][51];

int sol = 0;

int xx[8] = { -1,0,1,1,1,0,-1,-1 };
int yy[8] = { 1,1,1,0,-1,-1,-1,0 };

void bfs(int x, int y) {
	int dist = 0;
	queue<tuple<int, int, int>>q;
	q.push({ x,y,dist });
	visited[x][y] = 1;
	while (!q.empty()) {
		tie(x, y, dist) = q.front();
		q.pop();
		if (arr[x][y]) {
			sol = max(sol, dist);
			return;
		}
		for (int i = 0; i < 8; i++) {
			int tx =x+xx[i],ty=y+yy[i];
			if (tx < 0 || ty < 0 || tx >= N || ty >= M||visited[tx][ty]) {
				continue;
			}
			visited[tx][ty]=1;
			q.push({tx,ty,dist+1});
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!arr[i][j]) {
				memset(visited,0,sizeof(visited));
				bfs(i,j);
			}
		}
	}
	cout << sol <<'\n';
	return 0;
}