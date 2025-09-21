#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int dp[31][40001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<int>item(N + 1);

	int weight = 0;
	for (int i = 1; i <= N; i++) {
		cin >> item[i];
		weight +=item[i];
	}

	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= weight; j++) {
			// 추 사용 X
			dp[i][j] = dp[i - 1][j];

			// 같은 쪽에 i번째 추를 올림
			if (j - item[i] >= 0) {
				dp[i][j] |= dp[i - 1][j - item[i]];
			}
			// 반대쪽에 i번째 추를 올림
			dp[i][j] |=dp[i-1][abs(j-item[i])];

			// 구슬이랑 i번째 추를 같이 올림
			dp[i][j] |= dp[i-1][j + item[i]];
		}
	}

	int M;
	cin >> M;
	vector<int>marble(M);
	for (int i = 0; i < M; i++) {
		cin >> marble[i];
	}

	for (int m : marble) {
		if (dp[N][m]) {
			cout << "Y" << ' ';
		}
		else {
			cout << "N" << ' ';
		}
	}
	return 0;
}