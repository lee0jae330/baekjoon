#include<bits/stdc++.h>

using namespace std;

int N,K;

int visited[1000001];

void bfs(int x) {
	queue<int>q;
	q.push(x);
	visited[x] = 0;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		if(visited[x]>K)
			continue;
		for (int tx : {x + 1, x + (x / 2)}) {
			if (tx <= 1000000 && visited[tx] == -1) {
				visited[tx] = visited[x] + 1;
				q.push(tx);
			}
		}			
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	memset(visited,-1,sizeof(visited));
	cin >> N >> K;
	bfs(0);
	if (visited[N]!=-1&&visited[N] <= K) {
		cout << "minigimbob" <<'\n';
	}
	else {
		cout << "water" <<'\n';
	}
	return 0;
}