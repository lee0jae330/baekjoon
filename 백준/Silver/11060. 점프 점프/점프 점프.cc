#include<bits/stdc++.h>

using namespace std;

int N;
int arr[1001];
int visited[1001];

void bfs(int x) {
	queue<int>q;
	q.push(x);
	visited[x]=0;
	while (!q.empty()) {
		x = q.front();
		if (x >= N-1) {
			cout << visited[x] <<'\n';
			return;
		}
		q.pop();
		for (int i = 1; i <= arr[x]; i++) {
			int tmp = x+i;
			if (tmp >= N-1) {
				cout << visited[x]+1 <<'\n';
				return;
			}
			if(visited[tmp]!=-1)
				continue;
			visited[tmp] = visited[x] + 1;
			q.push(tmp);
		}
	}
	cout << -1 <<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	fill(visited,visited+1001,-1);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	bfs(0);
	return 0;
}