#include<iostream>
#include<queue>
#include<algorithm>
#include<memory.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int N, M, rx, ry, bx, by;

char arr[11][11];
int visited[11][11][11][11];

int flag;
int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };

void bfs() {
	queue<pair<pair<pair<int, int>, pair<int, int>>, int>>q;
	visited[rx][ry][bx][by]=1;
	q.push({ {{rx,ry},{bx,by}}, 0 });
	while (!q.empty()) {
		rx = q.front().first.first.first;
		ry = q.front().first.first.second;
		bx = q.front().first.second.first;
		by = q.front().first.second.second;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (i == 0) { //위
				if (ry == by) { //둘의 y좌표가 겹쳐있을 때
					if (rx < bx) { //빨간 공이 더 위에 있을때
						int tmp_rx = rx;
						int f = 0;
						while (1) {
							if (arr[tmp_rx][ry] == 'O') {
								f = 1; 
								break;
							}
							else if (arr[tmp_rx + xx[i]][ry] == '#')
								break;
							tmp_rx += xx[i];
						}

						int tmp_bx = bx;
						while (1) {
							if (arr[tmp_bx][by] == 'O') {
								f = 2; //이러면 파란 공도 구멍에 빠짐
								break;
							}
							else if (arr[tmp_bx + xx[i]][by] == '#'|| (!f&&tmp_bx+xx[i]==tmp_rx))
								break;
							
							tmp_bx += xx[i];
						}

						if (!visited[tmp_rx][ry][tmp_bx][by] && f!=2 && cnt + 1 <= 10) {
							if (f) {
								flag=1;
								return;
							}
							visited[tmp_rx][ry][tmp_bx][by] = 1;
							q.push({ {{tmp_rx, ry},{tmp_bx,by}},cnt + 1 });
						}
					}
					else { //파란 공이 더 위에 있을 때
						int tmp_bx = bx;
						int f = 0;
						while (1) {
							if (arr[tmp_bx][by] == 'O') {
								f = 2; //이러면 파란 공도 구멍에 빠짐
								break;
							}
							else if (arr[tmp_bx + xx[i]][by] == '#')
								break;
							tmp_bx += xx[i];
						}
						if(f)
							continue;
						int tmp_rx = rx;

						while (1) {
							if (arr[tmp_rx][ry] == 'O') {
								f = 1;
								break;
							}
							else if (arr[tmp_rx + xx[i]][ry] == '#'||tmp_rx+xx[i]==tmp_bx)
								break;
							tmp_rx += xx[i];
						}

						
						if (!visited[tmp_rx][ry][tmp_bx][by] && cnt + 1 <= 10) {
							if (f) {
								flag=1;
								return;
							}
							visited[tmp_rx][ry][tmp_bx][by] = 1;
							q.push({ {{tmp_rx, ry},{tmp_bx,by}},cnt + 1 });
						}
					}
				}
				else {
					int tmp_rx = rx, tmp_bx = bx;
					int tmp_flag = 0;
					while (1) {
						if (arr[tmp_rx][ry] == 'O') {
							tmp_flag = 1;
							break;
						}
						else if (arr[tmp_rx + xx[i]][ry] == '#')
							break;
						tmp_rx += xx[i];
					}

					int f = 0;
					while (1) {
						if (arr[tmp_bx][by] == 'O') {
							f = 1; // 파란 공이 구멍에 빠짐
							break;
						}
						else if (arr[tmp_bx + xx[i]][by] == '#')
							break;
						tmp_bx += xx[i];
					}

					if (!visited[tmp_rx][ry][tmp_bx][by] && !f && cnt + 1 <= 10) {
						if (tmp_flag) {
							flag = 1;
							return;
						}
						visited[tmp_rx][ry][tmp_bx][by] = 1;
						q.push({ {{tmp_rx, ry},{tmp_bx,by}},cnt + 1 });
					}
				}
			}
			else if (i == 1) {//오른쪽
				if (rx == bx) { //두 공 x좌표가 겹쳐있을 때
					if (ry > by) { // 빨간 공이 더 오른쪽에 있을 때
						int tmp_ry = ry;
						int f = 0;
						while (1) {
							if (arr[rx][tmp_ry] == 'O') { 
								f = 1;
								break;
							}
							else if (arr[rx][tmp_ry + yy[i]] == '#')
								break;
							tmp_ry += yy[i];
						}

						int tmp_by = by;
						while (1) {
							if (arr[bx][tmp_by] == 'O') { 
								f = 2;
								break;
							}
							else if (arr[bx][tmp_by + yy[i]] == '#'||(!f&&tmp_by+yy[i]==tmp_ry))
								break;
							tmp_by += yy[i];
						}

						if (!visited[rx][tmp_ry][bx][tmp_by] && f!=2 && cnt + 1 <= 10) {
							if (f) {
								flag=1;
								return;
							}
							visited[rx][tmp_ry][bx][tmp_by] = 1;
							q.push({ {{rx,tmp_ry},{bx,tmp_by}},cnt + 1 });
						}
					}

					else {
						int tmp_by = by;
						int f = 0;
						while (1) {
							if (arr[bx][tmp_by] == 'O') { //파란공도 빠짐
								f = 2;
								break;
							}
							else if (arr[bx][tmp_by + yy[i]] == '#')
								break;
							tmp_by += yy[i];
						}
						if(f)
							continue;
						int tmp_ry = ry;
						while (1) {
							if (arr[rx][tmp_ry] == 'O') {
								f = 1;
								break;
							}
							else if (arr[rx][tmp_ry + yy[i]] == '#'||tmp_ry+yy[i]==tmp_by)
								break;
							tmp_ry += yy[i];
						}

						if (!visited[rx][tmp_ry][bx][tmp_by] && cnt + 1 <= 10) {
							if (f) {
								flag=1;
								return;
							}
							visited[rx][tmp_ry][bx][tmp_by] = 1;
							q.push({ {{rx,tmp_ry},{bx,tmp_by}},cnt + 1 });
						}
					}
				}
				else {
					int tmp_ry = ry;
					int tmp_flag = 0;
					while (1) {
						if (arr[rx][tmp_ry] == 'O') { 
							tmp_flag = 1;
							break;
						}
						else if (arr[rx][tmp_ry + yy[i]] == '#')
							break;
						tmp_ry += yy[i];
					}

					int tmp_by = by;
					int f = 0;
					while (1) {
						if (arr[bx][tmp_by] == 'O') { 
							f = 1;
							break;
						}
						else if (arr[bx][tmp_by + yy[i]] == '#')
							break;
						tmp_by += yy[i];
					}

					if (!visited[rx][tmp_ry][bx][tmp_by] && !f && cnt + 1 <= 10) {
						if (tmp_flag) {
							flag = 1;
							return;
						}
						visited[rx][tmp_ry][bx][tmp_by] = 1;
						q.push({ {{rx,tmp_ry},{bx,tmp_by}},cnt + 1 });
					}
				}
			}
			else if (i == 2) { //아래쪽
				if (ry == by) { //둘의 y좌표가 겹쳐있을 때
					if (rx > bx) { //빨간 공이 더 아래에 있을때
						int tmp_rx = rx;
						int f = 0;
						while (1) {
							if (arr[tmp_rx][ry] == 'O') {
								f = 1; 
								break;
							}
							else if (arr[tmp_rx + xx[i]][ry] == '#')
								break;
							tmp_rx += xx[i];
						}

						int tmp_bx = bx;
						while (1) {
							if (arr[tmp_bx][by] == 'O') {
								f = 2; //이러면 파란 공도 구멍에 빠짐
								break;
							}
							else if (arr[tmp_bx + xx[i]][by] == '#'||(!f&&tmp_bx+xx[i]==tmp_rx))
								break;
							tmp_bx += xx[i];
						}

						if (!visited[tmp_rx][ry][tmp_bx][by] && f!=2 && cnt + 1 <= 10) {
							if (f) {
								flag=1;
								return;
							}
								
							visited[tmp_rx][ry][tmp_bx][by] = 1;
							q.push({ {{tmp_rx, ry},{tmp_bx,by}},cnt + 1 });
						}
					}
					else { //파란 공이 더 아래에 있을 때
						int tmp_bx = bx;
						int f = 0;
						while (1) {
							if (arr[tmp_bx][by] == 'O') {
								f = 1; //이러면 파란 공도 구멍에 빠짐
								break;
							}
							else if (arr[tmp_bx + xx[i]][by] == '#')
								break;
							tmp_bx += xx[i];
						}
						if(f)
							continue;

						int tmp_rx = rx;
						while (1) {
							if (arr[tmp_rx][ry] == 'O') {
								f = 1;
								break;
							}
							else if (arr[tmp_rx + xx[i]][ry] == '#'||tmp_rx+xx[i]==tmp_bx)
								break;
							tmp_rx += xx[i];
						}

						if (!visited[tmp_rx][ry][tmp_bx][by] && cnt + 1 <= 10) {
							if (f) {
								flag=1;
								return;
							}
							visited[tmp_rx][ry][tmp_bx][by] = 1;
							q.push({ {{tmp_rx, ry},{tmp_bx,by}},cnt + 1 });
						}
					}
				}
				else {
					int tmp_rx = rx, tmp_bx = bx;
					int tmp_flag = 0;
					while (1) {
						if (arr[tmp_rx][ry] == 'O') {
							tmp_flag = 1;
							break;
						}
						else if (arr[tmp_rx + xx[i]][ry] == '#')
							break;
						tmp_rx += xx[i];
					}

					int f = 0;
					while (1) {
						if (arr[tmp_bx][by] == 'O') {
							f = 1; // 파란 공이 구멍에 빠짐
							break;
						}
						else if (arr[tmp_bx + xx[i]][by] == '#')
							break;
						tmp_bx += xx[i];
					}

					if (!visited[tmp_rx][ry][tmp_bx][by] && !f && cnt + 1 <= 10) {
						if (tmp_flag) {
							flag = 1;
							return;
						}
						visited[tmp_rx][ry][tmp_bx][by]  = 1;
						q.push({ {{tmp_rx, ry},{tmp_bx,by}},cnt + 1 });
					}
				}
			}
			else { //왼쪽
				if (rx == bx) { //두 공 x좌표가 겹쳐있을 때
					if (ry < by) { // 빨간 공이 더 왼쪽에 있을 때
						int tmp_ry = ry;
						int f = 0;
						while (1) {
							if (arr[rx][tmp_ry] == 'O') { //파란공도 빠짐
								f = 1;
								break;
							}
							else if (arr[rx][tmp_ry + yy[i]] == '#')
								break;
							tmp_ry += yy[i];
						}

						int tmp_by = by;
						while (1) {
							if (arr[bx][tmp_by] == 'O') { //파란공도 빠짐
								f = 2;
								break;
							}
							else if (arr[bx][tmp_by + yy[i]] == '#'||(!f&&tmp_by+yy[i]==tmp_ry))
								break;
							tmp_by += yy[i];
						}


						if (!visited[rx][tmp_ry][bx][tmp_by] && f!=2 && cnt + 1 <= 10) {
							if (f) {
								flag=1;
								return;
							}
							visited[rx][tmp_ry][bx][tmp_by] = 1;
							q.push({ {{rx,tmp_ry},{bx,tmp_by}},cnt + 1 });
						}
					}

					else {
						int tmp_by = by;
						int f = 0;
						while (1) {
							if (arr[bx][tmp_by] == 'O') { //파란공도 빠짐
								f = 1;
								break;
							}
							else if (arr[bx][tmp_by + yy[i]] == '#')
								break;
							tmp_by += yy[i];
						}
						if(f)
							continue;

						int tmp_ry = ry;
						while (1) {
							if (arr[rx][tmp_ry] == 'O') { //파란공도 빠짐
								f = 1;
								break;
							}
							else if (arr[rx][tmp_ry + yy[i]] == '#'||tmp_ry+yy[i]==tmp_by)
								break;
							tmp_ry += yy[i];
						}

						if (!visited[rx][tmp_ry][bx][tmp_by] && cnt + 1 <= 10) {
							if (f) {
								flag=1;
								return;
							}
							visited[rx][tmp_ry][bx][tmp_by] = 1;
							q.push({ {{rx,tmp_ry},{bx,tmp_by}},cnt + 1 });
						}
					}
				}
				else {
					int tmp_ry = ry;
					int tmp_flag = 0;
					while (1) {
						if (arr[rx][tmp_ry] == 'O') { 
							tmp_flag = 1;
							break;
						}
						else if (arr[rx][tmp_ry + yy[i]] == '#')
							break;
						tmp_ry += yy[i];
					}

					int tmp_by = by;
					int f = 0;
					while (1) {
						if (arr[bx][tmp_by] == 'O') { 
							f = 1;
							break;
						}
						else if (arr[bx][tmp_by + yy[i]] == '#')
							break;
						tmp_by += yy[i];
					}

					if (!visited[rx][tmp_ry][bx][tmp_by] && !f && cnt + 1 <= 10) {
						if (tmp_flag) {
							flag = 1;
							return;
						}
						visited[rx][tmp_ry][bx][tmp_by] = 1;
						q.push({ {{rx,tmp_ry},{bx,tmp_by}},cnt + 1 });
					}
				}
			}
		}
	}
}

int main(void) {
	fastio();
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R')
				rx = i, ry = j;
			if (arr[i][j] == 'B')
				bx = i, by = j;
		}
	}
	bfs();
	if (flag) {
		cout << 1 << '\n';
	}
	else {
		cout << 0 << '\n';
	}
	return 0;
}