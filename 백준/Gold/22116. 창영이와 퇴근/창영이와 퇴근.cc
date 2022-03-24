#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<stdlib.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

#define INF 1e9+1

int arr[1001][1001];
int dist[1001][1001];

int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };


void dijk(int x, int y, int N) {
	priority_queue<pair<int, pair<int, int>>>pq;
	pq.push({ -arr[x][y],{x,y} });
	dist[x][y] = arr[x][y];
	int flag = 0;
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
				int cost = abs(arr[x][y] - arr[tx][ty]);
                if(flag)
					cost = max(cost, d);
				if (dist[tx][ty] > cost) {
						dist[tx][ty] = cost;
						pq.push({ -cost, {tx,ty} });
				}
			}
		}
		flag = 1;
	}

}

int main(void) {
	fastio();
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = INF;
		}
	}
	dijk(0, 0, N);
	dist[0][0] = 0;
	cout << dist[N - 1][N - 1] << '\n';
	
	return 0;
}