#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<memory.h>
#include<string.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<int> v[10001];
int visited[10001];
int check[10001];
int parent[10001];
void bfs(int x, int y) {
	queue<int> q;
	q.push(x);
	visited[x] = 1;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			if (!visited[v[x][i]]) {
				parent[v[x][i]] = x;
				visited[v[x][i]] =visited[x]+1;
				q.push(v[x][i]);
				if (v[x][i] == y)
					return;
			}
		}
	}
}

void bfs2(int x, int y) {
	queue<int> q;
	q.push(x);
	memset(visited, 0, sizeof(visited));
	visited[x] = 1;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			if (check[v[x][i]])
				continue;
			if (!visited[v[x][i]]) {
				visited[v[x][i]] = visited[x] + 1;
				q.push(v[x][i]);

				if (v[x][i] == y)
					return;
			}
		}
	}
}


int main(void) {
	fastio();
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}
	int x, y;
	cin >> x >> y;
	bfs(x, y);
	int result = visited[y] - 1;
	int tmp = result;
	int tmp1 = y;
	while (tmp > 0) {
		check[tmp1] = 1;
		tmp1 = parent[tmp1];
		tmp--;
	}
	check[x] = 0, check[y] = 0;
	bfs2(y, x);
	result += visited[x] - 1;
	cout << result << '\n';
	return 0;
}