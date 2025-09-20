#include<iostream>
#include<cstring>
#include<memory.h>
#include<vector>

using namespace std;

int dp[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		memset(dp, 0, sizeof(dp));

		int N;
		cin >> N;
		vector<int>coin(N);

		for (int i = 0; i < N; i++) {
			cin >> coin[i];
		}

		int M ;
		cin >> M;

		dp[0] = 1; 
		for (int c : coin) {
			for (int m = c; m <= M; m++) {
				dp[m] += dp[m-c];
			}
		}

		cout << dp[M] <<'\n';

	}
	return 0;
}