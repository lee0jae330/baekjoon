#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

#define INF 123456789

int arr[126][126];
int dist[126][126];

int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

void dijk(int x, int y, int N) {
	priority_queue<pair<int, pair<int, int>>>pq;
	pq.push({ -arr[x][y],{x,y} });
	dist[x][y] = arr[x][y];
	while (!pq.empty()) {
		int d = -pq.top().first;
		x = pq.top().second.first;
		y = pq.top().second.second;
		pq.pop();
		if (dist[x][y] < d)
			continue;
		for (int i = 0; i < 4; i++) {
			int tx = x + xx[i], ty = y + yy[i];
			if (tx >= 0 && ty >= 0 && tx < N && ty < N) {
				int cost = d + arr[tx][ty];
				if (cost < dist[tx][ty]) {
					dist[tx][ty] = cost;
					pq.push({ -cost,{tx,ty} });
				}
			}
		}
	}
}

int main(void) {
	fastio();
	int cnt = 1;
	while (1) {
		int N;
		cin >> N;
		if (!N)
			break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				cin >> arr[i][j];
		}
		memset(dist, INF, sizeof(dist));
		dijk(0, 0, N);
		cout << "Problem " << cnt << ": " << dist[N - 1][N - 1]<<'\n';
		cnt++;
	}
	return 0;
}