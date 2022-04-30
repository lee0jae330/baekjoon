#include<iostream>
#include<vector>
#include<set>
#include<memory.h>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

set<int>s[401];
int arr[21][21];
int like[21][21];
vector<int>v;
vector<pair<int, int>>l;
int Empty[21][21];
int N;
vector < pair<int, int>> maxEmpty;
int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };

void findEmpty(int target) {
	maxEmpty.clear();
	memset(Empty, 0, sizeof(Empty));
	int mx = 0;
	for (int i = 0; i < l.size(); i++) {
		int x = l[i].first, y = l[i].second;
		int cnt = 0;
		for (int k = 0; k < 4; k++) {
			int tx = x + xx[k], ty = y + yy[k];
			if (tx >= 0 && ty >= 0 && tx < N && ty < N) {
				if (!arr[tx][ty])
					cnt++;
			}
		}
		Empty[x][y] = cnt;
		mx = max(mx, cnt);
	}

	for (int i = 0; i < l.size(); i++) {
		int x = l[i].first, y = l[i].second;
		if (Empty[x][y] == mx) {
			maxEmpty.push_back({ x,y });
		}
	}

	sort(maxEmpty.begin(), maxEmpty.end());

	arr[maxEmpty[0].first][maxEmpty[0].second] = target;

}

void findLike(int x) {
	memset(like, 0, sizeof(like));
	int mx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int cnt = 0;
			if (arr[i][j])
				continue;
			for (int k = 0; k < 4; k++) {
				int tx = i + xx[k], ty = j + yy[k];
				if (tx >= 0 && ty >= 0 && tx < N && ty < N) {
					if (arr[tx][ty] && s[x].find(arr[tx][ty]) != s[x].end()) {
						cnt++;
					}
				}
			}
			like[i][j] = cnt;
			mx = max(cnt, mx);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!arr[i][j]&&like[i][j] == mx)
				l.push_back({ i,j });
		}
	}

	if (l.size() == 1) {
		arr[l[0].first][l[0].second] = x;
	}
	else {
		findEmpty(x);
	}
	l.clear();
}




int main(void) {
	fastio();
	cin >> N;
	for (int i = 0; i < N * N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
		for (int j = 0; j < 4; j++) {
			int n;
			cin >> n;
			s[num].insert(n);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		findLike(v[i]);
	}

	long long result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int cnt = 0;
			int x = arr[i][j];
			for (int k = 0; k < 4; k++) {
				int tx = i + xx[k], ty = j + yy[k];
				if (tx >= 0 && ty >= 0 && tx < N && ty < N) {
					if (s[x].find(arr[tx][ty]) != s[x].end()) {
						cnt++;
					}
				}
			}
			if (cnt == 1) {
				result += 1;
			}
			else if (cnt == 2) {
				result += 10;
			}
			else if (cnt == 3)
				result += 100;
			else if (cnt == 4)
				result += 1000;
		}
	}
	cout << result << '\n';
	return 0;
}