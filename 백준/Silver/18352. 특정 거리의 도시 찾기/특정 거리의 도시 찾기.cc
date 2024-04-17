#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<int>v[300001];
int visited[300001];
int dist[300001];
vector<int>result;

void bfs(int x) {
	queue<int>q;
	visited[x] = 1;
	q.push(x);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		int d = dist[x];
		for (int i = 0; i < v[x].size(); i++) {
			if (visited[v[x][i]])
				continue;
			dist[v[x][i]] = d + 1;
			q.push(v[x][i]);
			visited[v[x][i]] = 1;
		}	
	}
}

int main(void) {
	fastio();
	int N, M, K, X;
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	bfs(X);
	for (int i = 1; i <= N; i++) {
		if (dist[i] == K)
			result.push_back(i);
	}
	sort(result.begin(), result.end());
	if (result.size() == 0) {
		cout << -1 << '\n';
	}
	else {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << '\n';
		}
	}
	return 0;
	
}