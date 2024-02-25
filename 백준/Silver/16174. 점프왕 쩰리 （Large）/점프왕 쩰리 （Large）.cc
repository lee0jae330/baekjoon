#include<bits/stdc++.h>

using namespace std;

int N;

int arr[65][65];
int visited[65][65];

int xx[2] = { 0,1 };
int yy[2] = { 1,0 };

void bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop();
		if (x == N - 1 && y == N - 1) {
			cout << "HaruHaru"<<'\n';
			return;
		}
		int num = arr[x][y];
		for (int i = 0; i < 2; i++) {
			int tx = x + xx[i]*num, ty = y + yy[i]*num;
			if (tx >= N || ty >= N || visited[tx][ty])
				continue;
			visited[tx][ty] = 1;
			q.push({ tx,ty });
		}
	}
	cout << "Hing" <<'\n';
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
	bfs(0,0);

	return 0;
}