#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int N, M, K;

const int SIZE = (int)1e5 + 1;

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

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) {
		return;
	}

	if (ranking[x] < ranking[y]) {
		swap(x, y);
	}
	else if (ranking[x] == ranking[y]) {
		ranking[x]++;
	}

	parent[y] = x;
}

vector<pair<int, int>>v[SIZE];
int error[SIZE];
int visited[SIZE];

void dfs(int x, int color) {
	visited[x] = color;
	for (int i = 0; i < v[x].size(); i++) {
		auto [next, isEnemy] = v[x][i];
		if (visited[next] != -1) {
			if (!isEnemy) {
				if (color != visited[next]) {
					error[find(x)] =1;
				}
			}
			else {
				if (color == visited[next]) {
					error[find(x)] =1;
				}
			}
		}
		else {
			if (isEnemy) {
				dfs(next, color ? 0 : 1);
			}
			else {
				dfs(next, color);
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	fill(visited, visited+SIZE, -1);
	init();

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int t, x, y;
		cin >> t >> x >> y;
		merge(x, y);
		v[x].push_back({ y, t });
		v[y].push_back({ x,t });
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == -1) {
			dfs(i, 0);
		}
	}

	while (K--) {
		int x, y;
		cin >> x >> y;
		if (find(x) == find(y)) {
			if (error[find(x)]) {
				cout << "Error" <<'\n';
			}
			else if (visited[x] == visited[y]) {
				cout <<"Friend" <<'\n';
			} else if (visited[x]!=visited[y] ) {
				cout <<"Enemy" <<'\n';
			}
		}
		else {
			cout << "Unknown" <<'\n';
		}
	}

}