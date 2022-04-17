#include<iostream>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int arr[501][501];

int main(void) {
	fastio();
	int N, M, B;
	int mx=-1, mn=257;
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			mx = max(mx, arr[i][j]);
			mn = min(mn, arr[i][j]);
		}
	}
	int result = 999999999;
	int h = -1;
	for(int i = mx; i >= mn; i--) {
		int cnt = 0;
		int cur = B;
		int time = 0;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (i > arr[x][y]) { //설치
					cnt+=i-arr[x][y];
					time += (i-arr[x][y]);
				}
				else if (i < arr[x][y]) { //제거
					cur += arr[x][y] - i;
					time += 2*(arr[x][y]-i);
				}
				
			}
		}
		if (cnt > cur) { // 불가능
			time = -1;
		}
		if (time != -1) {
			if (result > time) {
				h = i;
				result = time;
			}
		}
	}
	cout << result << ' ' << h << '\n';
	return 0;
}