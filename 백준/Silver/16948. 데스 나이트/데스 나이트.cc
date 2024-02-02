#include<bits/stdc++.h>

using namespace std;

int N;

int visited[201][201];

int xx[6] = { -2,-2,0,0,2,2 };
int yy[6] = { -1,1,-2,2,-1,1 };

void bfs(int x, int y, int r, int c) {
	queue<pair<int,int>> q;
	q.push({x,y});
	visited[x][y]=0;

	while (!q.empty()) {
		tie(x,y) = q.front();
		if (r == x && c == y) {
			cout << visited[x][y] <<'\n';
			return;
		}
		q.pop();
		for (int i = 0; i < 6; i++) {
			int tx = x+xx[i], ty= y+yy[i];
			if(tx<0||ty<0||tx>=N||ty>=N)
				continue;
			if(visited[tx][ty]!=-1)
				continue;
			visited[tx][ty]= visited[x][y]+1;
			q.push({tx,ty});
		}
	}
	cout << -1 <<'\n';
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 201; i++) {
		fill(visited[i],visited[i]+201,-1);
	}
	cin >> N;
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	bfs(r1,c1,r2,c2);
	return 0;
}