#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[20][20];
int xx[4] = { -1,-1,-1,0 };
int yy[4] = { 1,0,-1,-1 };

int main(void) {
	fastio();
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++)
			cin >> arr[i][j];
	}
	int result = 0;
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			int cnt = 1;

			if (arr[i][j] == 1) {
				int x1 = 0, x2 = 0, x3 = 0, x4 = 0;
				if (i - 1 >= 0 && j + 1 < 19 && arr[i - 1][j + 1] == 1) {
					x1 = 1;
				}
				if (i - 1 >= 0 && arr[i - 1][j] == 1) {
					x2 = 1;
				}
				if (i - 1 >= 0 && j - 1 >= 0 && arr[i - 1][j - 1] == 1) {
					x3 = 1;
				}
				if (j - 1 >= 0 && arr[i][j - 1] == 1) {
					x4 = 1;
				}
				if (!x1) {
					cnt = 1;
					for (int k = 1; k <= 18; k++) {
						if (i + k >= 19 || j - k < 0)
							break;
						if (arr[i + k][j - k] == 1) {
							cnt++;
						}
						else
							break;

					}
					if (cnt == 5) {
						cout << 1 << '\n' << i + 4 + 1 << ' ' << j - 4 + 1 << '\n';
						return 0;
					}
				}
				if (!x2) {
					cnt = 1;
					for (int k = 1; k <= 18; k++) {
						if (i + k >= 19)
							break;
						if (arr[i + k][j] == 1) {
							cnt++;
						}
						else
							break;
					}
					if (cnt == 5) {
						cout << 1 << '\n' << i + 1 << ' ' << j + 1 << '\n';
						return 0;
					}
				}
				if (!x3) {
					cnt = 1;
					for (int k = 1; k <= 18; k++) {
						if (i + k >= 19 || j + k >= 19)
							break;
						if (arr[i + k][j + k] == 1) {
							cnt++;
						}
						else
							break;
					}
					if (cnt == 5) {
						cout << 1 << '\n' << i + 1 << ' ' << j + 1 << '\n';
						return 0;
					}
				}
				if (!x4) {
					cnt = 1;
					for (int k = 1; k <= 18; k++) {
						if (j + k >= 19)
							break;
						if (arr[i][j + k] == 1) {
							cnt++;
						}
						else {
							break;
						}
					}
					if (cnt == 5) {
						cout << 1 << '\n' << i + 1 << ' ' << j + 1 << '\n';
						return 0;
					}
				}

			}
			else if (arr[i][j] == 2) {
				int x1 = 0, x2 = 0, x3 = 0, x4 = 0;
				if (i - 1 >= 0 && j + 1 < 19 && arr[i - 1][j + 1] == 2) {
					x1 = 1;
				}
				if (i - 1 >= 0 && arr[i - 1][j] == 2) {
					x2 = 1;
				}
				if (i - 1 >= 0 && j - 1 >= 0 && arr[i - 1][j - 1] == 2) {
					x3 = 1;
				}
				if (j - 1 >= 0 && arr[i][j - 1] == 2) {
					x4 = 1;
				}
				if (!x1) {
					cnt = 1;
					for (int k = 1; k <= 18; k++) {
						if (i + k >= 19 || j - k < 0)
							break;
						if (arr[i + k][j - k] == 2) {
							cnt++;
						}
						else
							break;

					}
					if (cnt == 5) {
						cout << 2 << '\n' << i + 4 + 1 << ' ' << j - 4 + 1 << '\n';
						return 0;
					}
				}
				if (!x2) {
					cnt = 1;
					for (int k = 1; k <= 18; k++) {
						if (i + k >= 19)
							break;
						if (arr[i + k][j] == 2) {
							cnt++;
						}
						else
							break;
					}
					if (cnt == 5) {
						cout << 2 << '\n' << i + 1 << ' ' << j + 1 << '\n';
						return 0;
					}
				}
				if (!x3) {
					cnt = 1;
					for (int k = 1; k <= 18; k++) {
						if (i + k >= 19 || j + k >= 19)
							break;
						if (arr[i + k][j + k] == 2) {
							cnt++;
						}
						else
							break;
					}
					if (cnt == 5) {
						cout << 2 << '\n' << i + 1 << ' ' << j + 1 << '\n';
						return 0;
					}
				}
				if (!x4) {
					cnt = 1;
					for (int k = 1; k <= 18; k++) {
						if (j + k >= 19)
							break;
						if (arr[i][j + k] == 2) {
							cnt++;
						}
						else {
							break;
						}
					}
					if (cnt == 5) {
						cout << 2 << '\n' << i + 1 << ' ' << j + 1 << '\n';
						return 0;
					}
				}
				
			}
			else continue;
		}
	}
	cout << 0 << '\n';
	return 0;

}