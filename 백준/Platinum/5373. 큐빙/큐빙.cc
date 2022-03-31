#include<iostream>
#include<string>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

char arr[6][3][3];

void init() {
	for (int i = 0; i < 6; i++) {
		char c;
		switch (i) {
		case 0:
			c = 'w';
			break;
		case 1:
			c = 'r';
			break;
		case 2:
			c = 'b';
			break;
		case 3:
			c = 'o';
			break;
		case 4:
			c = 'g';
			break;
		default:
			c = 'y';
		}

		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				arr[i][j][k] = c;
			}
		}
	}
}

int main(void) {
	fastio();
	int T;
	cin >> T;
	while (T-- > 0) {
		init();
		int n;
		cin >> n;
		for (int a = 0; a < n; a++) {
			string str;
			cin >> str;
			char dir = str[0], spin = str[1];
			char tmp1[3];
			char tmp2[3][3];
			if (dir == 'U') {
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						tmp2[i][j] = arr[0][i][j];
					}
				}

				for (int i = 0; i < 3; i++) {
					tmp1[i] = arr[3][0][i];
				}

				if (spin == '+') {

					for (int i = 0, j = 0; i < 3; i++) {
						arr[j][i][2] = tmp2[0][i];
						arr[j][2][2 - i] = tmp2[i][2];
						arr[j][i][0] = tmp2[2][i];
						arr[j][0][2 - i] = tmp2[i][0];
					}

					for (int i = 0; i < 3; i++) {
						arr[3][0][i] = arr[4][0][i];
					}

					for (int i = 0; i < 3; i++) {
						arr[4][0][i] = arr[1][0][i];
					}

					for (int i = 0; i < 3; i++) {
						arr[1][0][i] = arr[2][0][i];
					}

					for (int i = 0; i < 3; i++) {
						arr[2][0][i] = tmp1[i];
					}

				}
				else {

					for (int i = 0, j = 0; i < 3; i++) {
						arr[j][2 - i][0] = tmp2[0][i];
						arr[j][2][i] = tmp2[i][0];
						arr[j][2 - i][2] = tmp2[2][i];
						arr[j][0][i] = tmp2[i][2];
					}

					for (int i = 0; i < 3; i++) {
						arr[3][0][i] = arr[2][0][i];
					}

					for (int i = 0; i < 3; i++) {
						arr[2][0][i] = arr[1][0][i];
					}

					for (int i = 0; i < 3; i++) {
						arr[1][0][i] = arr[4][0][i];
					}

					for (int i = 0; i < 3; i++) {
						arr[4][0][i] = tmp1[i];
					}

				}
			}
			else if (dir == 'F') {

				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						tmp2[i][j] = arr[1][i][j];
					}
				}

				for (int i = 0; i < 3; i++) {
					tmp1[i] = arr[0][2][i];
				}

				if (spin == '+') {

					for (int i = 0, j = 1; i < 3; i++) {
						arr[j][i][2] = tmp2[0][i];
						arr[j][2][2 - i] = tmp2[i][2];
						arr[j][i][0] = tmp2[2][i];
						arr[j][0][2 - i] = tmp2[i][0];
					}

					for (int i = 0; i < 3; i++) {
						arr[0][2][2 - i] = arr[4][i][2];
					}

					for (int i = 0; i < 3; i++) {
						arr[4][i][2] = arr[5][0][i];
					}

					for (int i = 0; i < 3; i++) {
						arr[5][0][2 - i] = arr[2][i][0];
					}

					for (int i = 0; i < 3; i++) {
						arr[2][i][0] = tmp1[i];
					}

				}
				else {

					for (int i = 0, j = 1; i < 3; i++) {
						arr[j][2 - i][0] = tmp2[0][i];
						arr[j][2][i] = tmp2[i][0];
						arr[j][2 - i][2] = tmp2[2][i];
						arr[j][0][i] = tmp2[i][2];
					}

					for (int i = 0; i < 3; i++) {
						arr[0][2][i] = arr[2][i][0];
					}

					for (int i = 0; i < 3; i++) {
						arr[2][2 - i][0] = arr[5][0][i];
					}

					for (int i = 0; i < 3; i++) {
						arr[5][0][i] = arr[4][i][2];
					}

					for (int i = 0; i < 3; i++) {
						arr[4][2 - i][2] = tmp1[i];
					}

				}
			}
			else if (dir == 'R') {
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						tmp2[i][j] = arr[2][i][j];
					}
				}

				for (int i = 0; i < 3; i++) {
					tmp1[i] = arr[0][i][2];
				}

				if (spin == '+') {


					for (int i = 0, j = 2; i < 3; i++) {
						arr[j][i][2] = tmp2[0][i];
						arr[j][2][2 - i] = tmp2[i][2];
						arr[j][i][0] = tmp2[2][i];
						arr[j][0][2 - i] = tmp2[i][0];
					}

					for (int i = 0; i < 3; i++) {
						arr[0][i][2] = arr[1][i][2];
					}

					for (int i = 0; i < 3; i++) {
						arr[1][i][2] = arr[5][i][2];
					}

					for (int i = 0; i < 3; i++) {
						arr[5][2-i][2] = arr[3][i][0];
					}

					for (int i = 0; i < 3; i++) {
						arr[3][2 - i][0] = tmp1[i];
					}
				}
				else {

					for (int i = 0, j = 2; i < 3; i++) {
						arr[j][2 - i][0] = tmp2[0][i];
						arr[j][2][i] = tmp2[i][0];
						arr[j][2 - i][2] = tmp2[2][i];
						arr[j][0][i] = tmp2[i][2];
					}

					for (int i = 0; i < 3; i++) {
						arr[0][i][2] = arr[3][2 - i][0];
					}

					for (int i = 0; i < 3; i++) {
						arr[3][2 - i][0] = arr[5][i][2];
					}

					for (int i = 0; i < 3; i++) {
						arr[5][i][2] = arr[1][i][2];
					}
					for (int i = 0; i < 3; i++) {
						arr[1][i][2] = tmp1[i];
					}

				}
			}
			else if (dir == 'B') {
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						tmp2[i][j] = arr[3][i][j];
					}
				}

				for (int i = 0; i < 3; i++) {
					tmp1[i] = arr[0][0][i];
				}

				if (spin == '+') {


					for (int i = 0, j = 3; i < 3; i++) {
						arr[j][i][2] = tmp2[0][i];
						arr[j][2][2 - i] = tmp2[i][2];
						arr[j][i][0] = tmp2[2][i];
						arr[j][0][2 - i] = tmp2[i][0];
					}

					for (int i = 0; i < 3; i++) {
						arr[0][0][i] = arr[2][i][2];
					}

					for (int i = 0; i < 3; i++) {
						arr[2][2 - i][2] = arr[5][2][i];
					}

					for (int i = 0; i < 3; i++) {
						arr[5][2][i] = arr[4][i][0];
					}

					for (int i = 0; i < 3; i++) {
						arr[4][2 - i][0] = tmp1[i];
					}

				}
				else {

					for (int i = 0, j = 3; i < 3; i++) {
						arr[j][2 - i][0] = tmp2[0][i];
						arr[j][2][i] = tmp2[i][0];
						arr[j][2 - i][2] = tmp2[2][i];
						arr[j][0][i] = tmp2[i][2];
					}

					for (int i = 0; i < 3; i++) {
						arr[0][0][2 - i] = arr[4][i][0];
					}

					for (int i = 0; i < 3; i++) {
						arr[4][i][0] = arr[5][2][i];
					}

					for (int i = 0; i < 3; i++) {
						arr[5][2][2 - i] = arr[2][i][2];
					}

					for (int i = 0; i < 3; i++) {
						arr[2][i][2] = tmp1[i];
					}
				}
			}
			else if (dir == 'L') {
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						tmp2[i][j] = arr[4][i][j];
					}
				}

				for (int i = 0; i < 3; i++) {
					tmp1[i]=arr[0][i][0];
				}

				if (spin == '+') {

					for (int i = 0, j = 4; i < 3; i++) {
						arr[j][i][2] = tmp2[0][i];
						arr[j][2][2 - i] = tmp2[i][2];
						arr[j][i][0] = tmp2[2][i];
						arr[j][0][2 - i] = tmp2[i][0];
					}

					for (int i = 0; i < 3; i++) {
						arr[0][2-i][0]=arr[3][i][2];
					}

					for (int i = 0; i < 3; i++) {
						arr[3][2-i][2]=arr[5][i][0];
					}

					for (int i = 0; i < 3; i++) {
						arr[5][i][0]=arr[1][i][0];
					}

					for (int i = 0; i < 3; i++) {
						arr[1][i][0]=tmp1[i];
					}


				}
				else {

					for (int i = 0, j = 4; i < 3; i++) {
						arr[j][2 - i][0] = tmp2[0][i];
						arr[j][2][i] = tmp2[i][0];
						arr[j][2 - i][2] = tmp2[2][i];
						arr[j][0][i] = tmp2[i][2];
					}

					for (int i = 0; i < 3; i++) {
						arr[0][i][0]=arr[1][i][0];
					}

					for (int i = 0; i < 3; i++) {
						arr[1][i][0]=arr[5][i][0];
					}

					for (int i = 0; i < 3; i++) {
						arr[5][2-i][0]=arr[3][i][2];
					}

					for (int i = 0; i < 3; i++) {
						arr[3][2-i][2]=tmp1[i];
					}

				}
			}
			else {
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						tmp2[i][j] = arr[5][i][j];
					}
				}

				for (int i = 0; i < 3; i++) {
					tmp1[i]=arr[3][2][i];
				}

				if (spin == '+') {

					for (int i = 0, j = 5; i < 3; i++) {
						arr[j][i][2] = tmp2[0][i];
						arr[j][2][2 - i] = tmp2[i][2];
						arr[j][i][0] = tmp2[2][i];
						arr[j][0][2 - i] = tmp2[i][0];
					}
					
					for (int i = 0; i < 3; i++) {
						arr[3][2][i]=arr[2][2][i];
					}

					for (int i = 0; i < 3; i++) {
						arr[2][2][i]=arr[1][2][i];
					}

					for (int i = 0; i < 3; i++) {
						arr[1][2][i]=arr[4][2][i];
					}

					for (int i = 0; i < 3; i++) {
						arr[4][2][i]=tmp1[i];
					}

				}
				else {

					for (int i = 0, j = 5; i < 3; i++) {
						arr[j][2 - i][0] = tmp2[0][i];
						arr[j][2][i] = tmp2[i][0];
						arr[j][2 - i][2] = tmp2[2][i];
						arr[j][0][i] = tmp2[i][2];
					}

					for (int i = 0; i < 3; i++) {
						arr[3][2][i]=arr[4][2][i];
					}

					for (int i = 0; i < 3; i++) {
						arr[4][2][i]=arr[1][2][i];
					}

					for (int i = 0; i < 3; i++) {
						arr[1][2][i]=arr[2][2][i];
					}

					for (int i = 0; i < 3; i++) {
						arr[2][2][i]=tmp1[i];
					}
				}
			}
		}
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cout << arr[0][j][k];
			}
			cout << '\n';
		}
	}
	return 0;
}