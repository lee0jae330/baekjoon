#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int base[4][4];
int green[6][4];
int blue[4][6];
int score;

void setBlock_green(int t, int x, int y) {
	int col = 6;
	if (t == 2) {
		for (int i = 0; i < 6; i++) {
			if (green[i][y] || green[i][y + 1]) {
				col = i;
				break;
			}
		}
		green[col - 1][y] = 2, green[col - 1][y + 1] = 2;

	}
	else { // 1x1 , 2x1

		for (int i = 0; i < 6; i++) {
			if (green[i][y]) {
				col = i;
				break;
			}
		}
		if (t == 1) {
			green[col - 1][y] = 1;
		}
		else {
			green[col - 1][y] = 1;
			green[col - 2][y] = 1;
		}
	}



}

void setBlock_blue(int t, int x, int y) {
	int row = 6;
	if (t == 3) {  // 2x1
		for (int i = 0; i < 6; i++) {
			if (blue[x][i] || blue[x + 1][i]) {
				row = i;
				break;
			}
		}
		blue[x][row - 1] = 2, blue[x + 1][row - 1] = 2;
	}
	else { // 1x1 , 1x2
		for (int i = 0; i < 6; i++) {
			if (blue[x][i]) {
				row = i;
				break;
			}
		}
		if (t == 1) {
			blue[x][row - 1] = 1;
		}
		else {
			blue[x][row - 1] = 1, blue[x][row - 2] = 1;
		}
	}

}

vector<int> check_green() { // 연한부분 생각X 
	vector<int> col;
	for (int i = 2; i < 6; i++) {
		int flag = 0;
		for (int j = 0; j < 4; j++) {
			if (green[i][j] == 0) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			col.push_back(i);
		}
	}
	return col;
}


vector<int> check_blue() { //연한 부분 생각X
	vector<int>row;
	
	for (int i = 2; i < 6; i++) {
		int flag=0;
		for (int j = 0; j < 4; j++) {
			if (blue[j][i] == 0) {
				flag=1;
				break;
			}
		}
		if(!flag)
			row.push_back(i);
	}

	return row;
}

bool delete_green() {
	vector<int> col = check_green();
	if (col.size() == 0) {
		return false; // 가득찬 행 X
	}
	else {
		score+=col.size();
		for (int i = 0; i < col.size(); i++) {
			for (int j = 0; j < 4; j++) {
				green[col[i]][j] = 0;
			}
		}
		return true;
	}
}

bool delete_blue() {
	vector<int> row = check_blue();
	if (row.size() == 0)
		return false;
	else {
		score += row.size();
		for (int i = 0; i < row.size(); i++) {
			for (int j = 0; j < 4; j++) {
				blue[j][row[i]] = 0;
			}
		}
		return true;
	}
}

void move_green() {	
	int col=4;
	while (col >= 0) { // col이 delete된 행 중에서 가장 작은 행
		for (int i = 0; i < 4; i++) {
			if (green[col][i] == 2) { //1x2
				if (i == 3 || green[col][i + 1] != 2)
					continue;
				int tmp = -1; // 여기에는 블록 X 
				for (int j = col + 1; j < 6; j++) { //col+1부터 5행까지 블록이 있는지 탐색
					if (green[j][i] || green[j][i + 1]) {
						tmp = j; //블록이 있으면 행 대입.
						break;
					}
				}
				if (tmp == -1) { //tmp 값이 변하지않았으면 아래에는 쭉 00 임
					tmp = 6;
				}
				for (int j = col; j < tmp - 1; j++) { //해당 블록을 tmp-1 행까지 내리기
					green[j + 1][i] = green[j][i];
					green[j + 1][i + 1] = green[j][i + 1];
					green[j][i] = 0, green[j][i + 1] = 0;
				}
			}
			else if (green[col][i]==1) { // 1x1, 2x1 -> 어차피 세로 한칸이므로 내리는 연산은 동일
				int tmp = -1;
				for (int j = col + 1; j < 6; j++) {
					if (green[j][i]) {
						tmp = j;
						break;
					}
				}

				if (tmp == -1) {
					tmp = 6;
				}

				for (int j = col; j < tmp - 1; j++) {
					green[j + 1][i] = green[j][i];
					green[j][i] = 0;
				}
			}
		}
		col--;
		
	}
}

void move_blue() {
	
	int row=4;
	while (row >= 0) { // row이 delete된 행 중에서 가장 작은 행
	
		for (int i = 0; i < 4; i++) {
			if (blue[i][row] == 2) {
				if (i == 3 || blue[i + 1][row] != 2)
					continue;
				int tmp = -1 ; //  초기 row
				for (int j = row + 1; j < 6; j++) {
					if (blue[i][j] || blue[i + 1][j]) {
						tmp = j;
						break;
					}
				}
				if (tmp == -1)
					tmp = 6;

				for (int j = row; j < tmp - 1; j++) {
					blue[i][j + 1] = blue[i][j];
					blue[i + 1][j + 1] = blue[i + 1][j];
					blue[i][j] = 0, blue[i + 1][j] = 0;
				}
			}
			else if (blue[i][row]==1) {
				int tmp = -1; 

				for (int j = row+1; j < 6; j++) {
					if (blue[i][j]) {
						tmp = j;
						break;
					}
				}

				if (tmp == -1)
					tmp = 6;
				for (int j = row; j < tmp - 1; j++) {
					blue[i][j + 1] = blue[i][j];
					blue[i][j] = 0;
				}
				
			}
		}
		row--;
	}

}

int hasBlockOnSpecial_green() {
	for (int i = 0; i < 4; i++) {
		if(green[0][i])
			return 2;
	}
	for (int i = 0; i < 4; i++) {
		if (green[1][i])
			return 1;
	}
	return 0;
}

int hasBlockOnSpecial_blue() {
	for (int i = 0; i < 4; i++) {
		if(blue[i][0])
			return 2;
	}
	for (int i = 0; i < 4; i++) {
		if (blue[i][1])
			return 1;
	}
	return 0;
}

void shiftBlock_green(int n) {

	if (!n) {
		return;
	}
	else {
		if (n == 1) {
			for (int i = 0; i < 4; i++) {
				green[5][i]=0;
			}
			for (int i = 5; i >= 1; i--) {
				for (int j = 0; j < 4; j++) {
					green[i][j] = green[i - 1][j];
				}
			}
			for (int j = 0; j < 4; j++) {
				green[1][j] = 0,green[0][j]=0;
			}
		}
		else if (n == 2) {
			for (int i = 0; i < 4; i++) {
				green[5][i] = 0,green[4][i]=0;
			}
			for (int i = 5; i >= 2; i--) {
				for (int j = 0; j < 4; j++) {
					green[i][j] = green[i - 2][j];
				}
			}
			for (int j = 0; j < 4; j++) {
				green[0][j] = 0, green[1][j] = 0;
			}
		}
	}
}

void shiftBlock_blue(int n) {
	if(!n)
		return;
	else {
		if (n == 1) {
			for (int i = 0; i < 4; i++) {
				blue[i][5]=0;
			}

			for (int i = 5; i >= 1; i--) {
				for (int j = 0; j < 4; j++) {
					blue[j][i]=blue[j][i-1];
				}
			}
			for (int i = 0; i < 4; i++) {
				blue[i][1] = 0;
				blue[i][0]=0;
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				blue[i][5] = 0;
				blue[i][4]=0;
			}
			for (int i = 5; i >= 2; i--) {
				for (int j = 0; j < 4; j++) {
					blue[j][i]=blue[j][i-2];
				}
			}
			for (int j = 0; j < 4; j++) {
				blue[j][0]=0, blue[j][1]=0;
			}
		}
	}
}

void func_green() {
	while (1) {
		bool del= delete_green();
		if (del) {
			move_green();
		}
		else {
			int num = hasBlockOnSpecial_green();
			if (num==0) {
				return;
			}
			else {
				shiftBlock_green(num);
				return;
			}
		}
	}

}

void func_blue() {
	while (1) {
		bool del= delete_blue();
		if (del) {
			move_blue();
		}
		else {
			int num=hasBlockOnSpecial_blue();
			if(num==0)
				return;
			else {
				shiftBlock_blue(num);
				return;
			}
		}
	}
}

void func() {
	func_green();
	func_blue();
}


// case of green : 1x1 -> 1 , 1x2 -> 2 2 , 2x1 -> 1
//												  1

// case of blue : 1x1 -> 1, 1x2-> 1 1 , 2 x 1 -> 2
//											     2		



int main(void) {
	fastio();
	int N;
	cin >> N;
	while (N > 0) {
		int t, x, y;
		cin >> t >> x >> y;
		setBlock_green(t, x, y);
		setBlock_blue(t, x, y);
		func();
		/*for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 4; j++) {
				cout <<green[i][j];
			}
			cout <<'\n';
		}
		cout <<"------------------"<<'\n';
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 6; j++) {
				cout << blue[i][j];
			}
			cout <<'\n';
		}*/
	
		N--;
	}
	cout << score << '\n';
	int cnt = 0;
	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (green[i][j])
				cnt++;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 2; j < 6; j++) {
			if (blue[i][j])
				cnt++;
		}
	}
	cout << cnt << '\n';
	
	return 0;
}
