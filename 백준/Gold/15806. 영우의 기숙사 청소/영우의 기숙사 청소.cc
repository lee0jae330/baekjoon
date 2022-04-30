#include<iostream>
#include<queue>
#include<vector>
#include<memory.h>
using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[301][301];
int N, M, K, t;
queue<pair<int, int>>fungi[2];
vector<pair<int, int>>check;
int xx[8] = { -2,-1,1,2,2,1,-1,-2 };
int yy[8] = { 1,2,2,1,-1,-2,-2,-1 };
int visited[2][301][301];

void spread() {
	int cnt = 0;
	int d = t;

	for (int d = 0; d < t; d++) {
		while (!fungi[d % 2].empty()) {
			int x = fungi[d%2].front().first;
			int y = fungi[d%2].front().second;
			fungi[d % 2].pop();
		
			for (int i = 0; i < 8; i++) {
				int tx = x + xx[i], ty = y + yy[i];
				if (tx > 0 && ty > 0 && tx <= N && ty <= N && !visited[(d + 1) % 2][tx][ty]) {
					visited[(d+ 1) % 2][tx][ty] = 1;
					fungi[(d+1)%2].push({tx,ty});
				}
			}
		}
	}
	
}

int main(void) {
	fastio();
	cin >> N >> M >> K >> t;
	int sx, sy;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		sx = x, sy = y;
		fungi[0].push({x,y});
		visited[0][x][y] = 1; //홀수일 , 짝수일 방문으로 구분
	}

	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		check.push_back({ x ,y });
	}
	
	spread();

	if (N == 1 || N == 2) {
		cout << "NO" << '\n';
		return 0;
	}

	if (N == 3&&M==1) {
		if (sx == 1 && sy == 1) {
			cout << "NO" << '\n';
			return 0;
		}
	}

	for (int i = 0; i < check.size(); i++) {
		if (visited[t%2][check[i].first][check[i].second]) {
			cout << "YES" << '\n';
			return 0;
		}
	}
	cout << "NO" << '\n';
	return 0;
}
