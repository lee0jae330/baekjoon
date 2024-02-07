#include<bits/stdc++.h>

using namespace std;

int arr[101][101];
int N, M;
int visited[101][101];

int sol = 0;

int xx[8] = { -1,0,1,1,1,0,-1,-1 };
int yy[8] = { 1,1,1,0,-1,-1,-1,0 };

void bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = 1;
	int flag = 0;
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int tx = x + xx[i], ty = y + yy[i];
			if (tx < 0 || ty < 0 || tx >= N || ty >= M) {
				continue;
			}
			if (arr[tx][ty] > arr[x][y]) {
				flag = 1;
			}
			if (!visited[tx][ty] && (arr[tx][ty] == arr[x][y])) {
				visited[tx][ty] = 1;
				q.push({ tx,ty });
			}
		}
	}
	if (!flag) {
		sol++;
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
			if (!visited[i][j]) {
				bfs(i, j);
			}
			
		}
	}
	cout << sol << '\n';
	return 0;
}