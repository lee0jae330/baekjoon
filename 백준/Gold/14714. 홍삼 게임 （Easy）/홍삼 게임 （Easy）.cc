#include<bits/stdc++.h>

using namespace std;

int N, A, B, DA, DB;

int visited[501][501];

void bfs(int x, int y, int cnt) {
	queue<tuple<int,int,int>>q;
	q.push({x,y,cnt});
	visited[x][y]=1;
	int sol = 1e9;
	while (!q.empty()) {
		tie(x,y,cnt) = q.front();
		q.pop();
		int tx1 = x + DA, tx2 = x-DA; //지목
		int tmp = cnt+1;
		if(tx1>N)
			tx1%=N;
		if(tx2<=0)
			tx2 += N;
		if (tx1 == y || tx2 == y) {
			sol = min(sol,tmp);
		}
		int ty1 = y+DB , ty2 = y-DB; //b 지목
		if(ty1>N)
			ty1%=N;
		if(ty2<=0)
			ty2+=N;
		tmp++;
		if (ty1 == tx1 || ty1 == tx2 || ty2 == tx1 || ty2 == tx2) {
			sol = min(sol, tmp);
		}
		for (int tx : {tx1, tx2}) {
			for (int ty : {ty1, ty2}) {
				if (!visited[tx][ty]) {
					visited[tx][ty]=1;
					q.push({tx,ty,tmp});
				}
			}
		}
	}
	if(sol==1e9)
		cout <<"Evil Galazy" <<'\n';
	else
		cout << sol <<'\n';
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	cin >> N >> A >> B >> DA >> DB;

	bfs(A,B,0);

	return 0;
}