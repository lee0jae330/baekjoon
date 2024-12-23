#include<iostream>
#include<queue>
#include<algorithm>
#include<tuple>
#include<vector>
#include<map>
#include<utility>

using namespace std;

int N, M;

char arr[51][51];
int visited[51][51];

map<pair<int,int>,int>m;

int xx[4] = { 1,0,-1,0 };
int yy[4] = { 0,1,0,-1 };

priority_queue<tuple<int,int,int>>pq;

void bfs(int x, int y) {
	int sx=x, sy=y;
	queue<pair<int,int>>q;
	q.push({x, y});
	visited[x][y] = 0;
	while (!q.empty()) {
		tie (x,y) = q.front();
		if (arr[x][y] =='K') {
			int num = m[{x,y}];
			if (m[{sx, sy}] < num) {
				pq.push({- visited[x][y], m[{sx, sy}], num});
			}
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx= x +xx[i], ty= y+yy[i];
			if (tx < 0 || ty < 0 || tx >= N || ty >= N || visited[tx][ty] != -1 || arr[tx][ty] == '1') {
				continue;
			}
			visited[tx][ty] = visited[x][y]+1;
			q.push({tx,ty});
		}
	}
}

const int SIZE = 50 * 50 + 1;
int parent[SIZE];
int ranking[SIZE];

void init() {
	for (int i = 0; i < SIZE; i++) {
		parent[i] = i;
		ranking[i] = 0;
	}
}

int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) {
		return false;
	}

	if (ranking[x] < ranking[y]) {
		swap(x,y);
	}
	else if (ranking[x] == ranking[y]) {
		ranking[x]++;
	}
	parent[y] = x;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	for (int i = 0; i < 51; i++) {
		fill(visited[i], visited[i]+51,-1);
	}

	cin >> N >> M;

	int cnt = 1;
	int sx, sy;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				sx = i, sy =j;
				m[{i,j}] = 0;
			}
			else if (arr[i][j] == 'K') {
				m[{i,j}]= cnt++;
			}
		}
	}
	bfs(sx,sy);
	for (auto iter : m) {
		auto [x,y] = iter.first;
		if (!iter.second) {
			continue;
		}
		if (visited[x][y] == -1) {
			cout << -1<<'\n';
			return 0;
		}


		for (int i = 0; i < 51; i++) {
			fill(visited[i], visited[i] + 51, -1);
		}
		
		bfs(x,y);
	}
	
	int sum = 0;
	while (!pq.empty()) {
		auto [cost, x,y] = pq.top();
		pq.pop();
		if (merge(x, y)) {
			sum += -cost;
		}
	}

	int root = find(0);
	for (auto& iter : m) {
		if (!iter.second) {
			continue;
		}

		
		if (root != find(iter.second)) {
			cout << -1 <<'\n';
			return 0;
		}
	}

	cout << sum <<'\n';
	return 0;
}