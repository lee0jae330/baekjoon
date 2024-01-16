#include<bits/stdc++.h>

using namespace std;

vector<int>v[20001];
int visited[20001];

int f =0;

void bfs(int x) {
	queue<int>q;
	q.push(x);
	visited[x]=0;
	while (!q.empty()) {
		x=q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int next = v[x][i];
			if (visited[next] != -1) {
				if (visited[next] == visited[x]) {
					cout << "NO"<<'\n';
					f=1;
					return;
				}
				continue;
			}
			else {
				if (!visited[x]) {
					visited[next] =1;
				}
				else
					visited[next] =0;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int K;
	cin >> K;
	while (K--) {
		fill(visited, visited + 20001, -1);
		f=0;
		for (int i = 0; i <= 20000; i++) {
			v[i].clear();
		}
		int V,E;
		cin >> V >> E;
		for (int i = 0; i < E; i++) {
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if (V == 1) {
			cout <<"YES" <<'\n';
			continue;
		}
		for (int i = 1; i <= V; i++) {
			if (visited[i] == -1) {
				bfs(i);
				if (f) {
					break;
				}
			}
		}
		if(!f)
			cout << "YES" <<'\n';
	}
	return 0;
}