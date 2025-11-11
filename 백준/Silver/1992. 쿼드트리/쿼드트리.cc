#include<bits/stdc++.h>

using namespace std;

int N;

char arr[65][65];

string rec(int x, int y, int sz) {
	char ch = arr[x][y];

	for (int i = x; i < x+sz; i++) {
		for (int j = y; j < y + sz; j++) {
			if (arr[i][j] != ch) {
				return '(' + rec(x,y, sz/2) + rec(x,y+sz/2,sz/2) + rec(x+sz/2, y, sz/2) + rec(x+sz/2, y+sz/2, sz/2) + ')';
			}
		}
	}
	string str = "";
	str.push_back(ch);
	return str;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	cout << rec(0,0,N) <<'\n';
	return 0;
}