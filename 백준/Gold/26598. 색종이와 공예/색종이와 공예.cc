//*g5 & #bfs & !@$me & %ko

#include<bits/stdc++.h>

using namespace std;

int N,M;

char arr[1001][1001];
int visited[1001][1001];

int xx[4] ={0,1,0,-1};
int yy[4] ={1,0,-1,0};

int flag = 0;

set<int>dir[1000001];

vector<pair<int,int>>v;

void bfs(int x, int y, int color) {
	int sz = 0;
	queue<pair<int,int>>q;
	visited[x][y] = color;
	q.push({x,y});

	
	while (!q.empty()) {
		tie(x,y) = q.front();
		q.pop();
		sz++;
		int cnt =0;
		for (int i = 0; i < 4; i++) {
			int tx = x+xx[i],ty=y+yy[i];
			if (tx < 0 || ty < 0 || tx >= N || ty >= M) {
				cnt++;
				continue;
			}
			if (arr[tx][ty] == arr[x][y]) {
				if (visited[tx][ty] == -1) {
					visited[tx][ty] = color;
					q.push({ tx,ty });
					dir[color].insert(i);
				}
			}
			else {
				cnt++;
			}
		}
		if (cnt >= 3) {
			v.push_back({x,y});
		}	
	}
	if (dir[color].size() >= 3) {
		flag =1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	  
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	memset(visited,-1,sizeof(visited));

	int num = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j]==-1) {
				bfs(i,j, num);
				num++;
			}
		}
	}

	if (flag) {
		cout <<"BaboBabo" <<'\n';
		return 0;
	}
	
	for (const auto& a : v) {
		set<int>adj;
		int x = a.first, y= a.second;
		for (int i = 0; i < 4; i++) {
			int tx = x+xx[i],ty=y+yy[i];
			if (tx < 0 || ty < 0 || tx >= N || ty >= M) {
				continue;
			}
			else {
				if (adj.find(visited[tx][ty]) == adj.end()) {
					adj.insert(visited[tx][ty]);
				}
				else { //이미 같은 구역이랑 이웃했음 -> 잘못된 모양
					cout << "BaboBabo" <<'\n';
					return 0;
				}
			}
		}
		int color = visited[x][y];
		if (!dir[color].empty() && dir[color].size() != 1) {
			cout <<"BaboBabo" <<'\n';
			return 0;
		}
	}
	cout << "dd" <<'\n';
	return 0;

}