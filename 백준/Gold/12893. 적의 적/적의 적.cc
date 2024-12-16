#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int SIZE = 2004;

int parent[SIZE];
vector<int>v[SIZE];
int visited[SIZE];
bool check = false;

void init() {
	for (int i = 0; i < SIZE; i++) {
		parent[i] = i;
	}
}

int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

void dfs(int x) {
	if (check) {
		return;
	}
	visited[x] = 1;
	int rootX = find(x);
	for (int i = 0; i < v[x].size(); i++) {
		int adj = v[x][i];
		int rootAdj = find(adj);
		if (rootAdj == rootX) {
			check = true;
			return;
		} 

		if (rootAdj == adj) {
			if (rootX == 2001) {
				parent[adj] = 2002;
			}
			else {
				parent[adj] = 2001;
			}
		}
	}

	for (int i = 0; i < v[x].size(); i++) {
		int adj = v[x][i];
		if (visited[adj]) {
			continue;
		}
		dfs(adj);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	int N ,M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			if (i == find(i)) {
				parent[i] = 2001;
			}
			dfs(i);
		}
	}
	if (check) {
		cout << 0 <<'\n';
		return 0;
	}
	cout << 1 <<'\n';
	return 0;
}