#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int N, M;
int arr[51][51];
int arr1[51][51];
vector <int>v;
vector<pair<pair<int, int>, int>>rcs;
void spin(int r, int c, int s) {
	int sr = r - s - 1, sc = c - s - 1;
	int er = r + s - 1, ec = c + s - 1;
	int num = er - sr;
	for (int i = 0; i < num / 2; i++) {
		int tmp = arr[sr + i][sc + i];
		int x = sr + i, y = sc + i;
		int ex = er - i, ey = ec - i;
		
		for (int j = x+ 1; j <= ex; j++) {
			arr[j - 1][y] = arr[j][y];
		}

		for (int j = y + 1 ; j <= ey; j++) {
			arr[ex][j - 1] = arr[ex][j];
		}

		for (int j = ex - 1 ; j >= x; j--) {
			arr[j + 1][ey] = arr[j][ey];
		}

		for (int j = ey - 1; j >= y+ 1; j--) {
			arr[x][j + 1] = arr[x][j];
		}
		arr[x][y + 1] = tmp;

		
	}
	
}

int main(void) {
	fastio();
	int K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			arr1[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		v.push_back(i);
		rcs.push_back({ {r,c},s });
	}
	int result = 100001;

	do {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				arr[i][j] = arr1[i][j];
		}
		for (int i = 0; i < v.size(); i++) {
			spin(rcs[v[i]].first.first, rcs[v[i]].first.second, rcs[v[i]].second);
		}

		for (int i = 0; i < N; i++) {
			int tmp = 0;
			for (int j = 0; j < M; j++) {
				tmp += arr[i][j];
			}
			result = min(result, tmp);
		}
	} while (next_permutation(v.begin(), v.end()));
	cout << result << '\n';
	return 0;
}