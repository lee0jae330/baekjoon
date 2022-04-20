#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

string arr[3];

int main(void) {
	fastio();
	arr[0] = "qwertyuiop";
	arr[1] = "asdfghjkl";
	arr[2] = "zxcvbnm";
	char sl, sr;
	cin >> sl >> sr;
	string str;
	cin >> str;
	int result = 0;
	int len = str.length();
	int rx, ry, lx, ly;

	for (int i = 0; i < len; i++) {
		char c = str[i];
		int xidx, yidx;
		for (int j = 0; j < 3; j++) {
			if (arr[j].find(c) != string::npos) {
				yidx = arr[j].find(c);
				xidx = j;
				break;
			}
		}
		if (xidx == 0) {
			if (yidx >= 5) { //right
				for (int j = 0; j < 3; j++) {
					if (arr[j].find(sr) != string::npos) {
						ry = arr[j].find(sr);
						rx = j;
						break;
					}
				}
				result += abs(rx - xidx) + abs(ry - yidx)+1;
				sr = c;
			}
			else { //left
				for (int j = 0; j < 3; j++) {
					if (arr[j].find(sl) != string::npos) {
						ly = arr[j].find(sl);
						lx = j;
						break;
					}
				}
				result += abs(lx - xidx) + abs(ly - yidx) + 1;
				sl=c;
			}
		}
		else if (xidx == 1) {
			if (yidx >= 5) {
				for (int j = 0; j < 3; j++) {
					if (arr[j].find(sr) != string::npos) {
						ry = arr[j].find(sr);
						rx = j;
						break;
					}
				}
				result += abs(rx - xidx) + abs(ry - yidx) + 1;
				sr = c;

			}
			else {
				for (int j = 0; j < 3; j++) {
					if (arr[j].find(sl) != string::npos) {
						ly = arr[j].find(sl);
						lx = j;
						break;
					}
				}
				result += abs(lx - xidx) + abs(ly - yidx) + 1;
				sl = c;

			}
		}
		else {
			if (yidx >= 4) {
				for (int j = 0; j < 3; j++) {
					if (arr[j].find(sr) != string::npos) {
						ry = arr[j].find(sr);
						rx = j;
						break;
					}
				}
				result += abs(rx - xidx) + abs(ry - yidx) + 1;
				sr = c;

			}
			else {
				for (int j = 0; j < 3; j++) {
					if (arr[j].find(sl) != string::npos) {
						ly = arr[j].find(sl);
						lx = j;
						break;
					}
				}
				result += abs(lx - xidx) + abs(ly - yidx) + 1;
				sl = c;

			}
		}
	}
	cout << result << '\n';
	return 0;
}