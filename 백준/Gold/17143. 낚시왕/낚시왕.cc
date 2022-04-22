#include<iostream>
#include<vector>
#include<memory.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[101][101];
int comp[101][101];
int R, C, M;

class shark {
public:
	int dir; // 1: 위 2: 아래 , 3: 오른쪽 4: 왼쪽
	int speed;
	int size;
public:
	shark() {

	}
	shark(int speed, int dir, int size) {
		this->speed = speed;
		this->dir = dir;
		this->size = size;
	}
};

vector<shark> v; //arr[x][y]-1 로 접근

int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,1,-1 };

void move() {
	memset(comp, 0, sizeof(comp));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j]) {
				shark &sk = v[arr[i][j] - 1];
				int sp = sk.speed;
				int x = i, y = j;
				int d = sk.dir;
				int cnt = 0;

				while (1) {
					if (cnt == sp)
						break;
					if (d == 1) { //위 
						if (x == 0) { //시작부터 맨위일 경우 or 맨 위에 온 경우
							sk.dir = 2;
							d = 2;
						}
						else {
							x--;
							cnt++;
						}
					}
					else if (d == 2) { //아래
						if (x == R - 1) { //맨 아래면 방향 전환
							sk.dir = 1;
							d = 1;
						}
						else {
							x++;
							cnt++;
						}
					}
					else if (d == 3) { //오른쪽
						if (y == C - 1) {
							sk.dir = 4;
							d = 4;
						}
						else {
							y++;
							cnt++;
						}
					}
					else { //왼쪽
						if (y == 0) {
							sk.dir = 3;
							d = 3;
						}
						else {
							y--;
							cnt++;
						}
					}
				}
				
				if (comp[x][y]) {
					if (v[comp[x][y] - 1].size < sk.size) {
						comp[x][y] = arr[i][j];
					}
				}
				else {
					comp[x][y] = arr[i][j];
				}
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for(int j = 0; j < C; j++)
			arr[i][j] = comp[i][j];
	}
}

int main(void) {
	fastio();
	cin >> R >> C >> M;
	for (int i = 1; i <= M; i++) {
		int r, c, s, d, z ;
		cin >> r >> c >> s >> d >> z;
		arr[r - 1][c - 1] = i;
		v.push_back(shark(s, d, z));
	}
	int result = 0;
	int person = -1;

	while (person < C) {
		int flag = 0;
		person++;
		for (int i = 0; i < R; i++) {
			if (arr[i][person]) { //땅에서 가장 가까운 상어 발견 시
				shark sk = v[arr[i][person] - 1];
				result += sk.size;
				arr[i][person] = 0;
				break;
			}
		}

		/*상어들 이동*/
		move();

	}
	cout << result << '\n';
	return 0;
}