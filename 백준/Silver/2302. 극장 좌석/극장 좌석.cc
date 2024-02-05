#include<bits/stdc++.h>

using namespace std;

int check[41];
int dp[41][3]; // 0: 가만히, 1: 오른쪽, 2: 왼쪽

int result = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		check[num]=1;
	}
	check[0] = 1;
	dp[1][0] = 1;
	if(!check[2]&&2<=N)
		dp[1][1] =1;
	dp[1][2] = 0;

	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][2];
		if (check[i]) {
			continue;
		}
		if(!check[i+1]&&i+1<=N)
			dp[i][1] = dp[i-1][0]+dp[i-1][2];
		if(!check[i-1])
			dp[i][2] = dp[i-1][1];
	}

	cout << dp[N][0]+dp[N][1]+dp[N][2] <<'\n';
	return 0;
}