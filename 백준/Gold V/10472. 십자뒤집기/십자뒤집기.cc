//* g5& #bfs & !@$me&% ko

#include<bits/stdc++.h>

using namespace std;

int P;

char arr[3][3];


int visited[100000];

vector<int> v = { 1,2,4,8,16,32,64,128,256 };

int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

void bfs(int x) {
	queue<int>q;
	q.push(x);
	visited[x] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		char field[3][3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				field[i][j] ='.';
			}
		}

		int cnt = 0;

		for (int i = 0; i < v.size(); i++) {
			if (v[i] == (x & v[i])) {
				cnt++;
				int r = i / 3, c = i % 3;
				
				if (field[r][c] == '.') {
					field[r][c] = '*';
				}
				else {
					field[r][c] = '.';

				}

				for (int k = 0; k < 4; k++) {
					int tx = r+xx[k],ty=c+yy[k];
					if(tx<0||ty<0||tx>=3||ty>=3)
						continue;
					if (field[tx][ty] == '.') {
						field[tx][ty]='*';
					}
					else {
						field[tx][ty] = '.';
					}
				}
			}
		}
		int flag =0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (arr[i][j] != field[i][j]) {
					flag =1;
				}
			}
		}
		if (!flag) {
			cout <<cnt << '\n';
			return;
		}

		for (int num : v) {
			if (!visited[x + num]) {
				visited[x+num]=1;
				q.push({x+num});
			}
		}
	}

}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> P;


	while (P--) {
		memset(visited,0,sizeof(visited));

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> arr[i][j];
			}
		}

		bfs(0);

	}
	return 0;
}