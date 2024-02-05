#include<bits/stdc++.h>

using namespace std;

int arr[100001][3];
int dp[100001][3];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int k =1;
	while (1) {
		for (int i = 0; i < 100001; i++) {
			fill(dp[i], dp[i] + 3, INT_MAX);
		}

		int N;
		cin >> N;
		if(!N)
			return 0;
		for (int i = 0; i < N; i++) {
			for(int j=0;j<3;j++)
				cin >> arr[i][j];
		}

		dp[0][1] = arr[0][1];
		dp[0][2] = dp[0][1] + arr[0][2];

		for (int i = 1; i < N; i++) {
			if (i == 1) {
				dp[i][0] = dp[i-1][1] + arr[i][0];
				dp[i][1] = min(dp[i][0],min(dp[i-1][1],dp[i-1][2])) + arr[i][1];
				dp[i][2] = min(dp[i-1][1],min(dp[i-1][2],dp[i][1])) + arr[i][2];
			}
			else {
				dp[i][0] = min(dp[i-1][0],dp[i-1][1]) + arr[i][0];
				dp[i][1] = min(dp[i][0],min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))) + arr[i][1];
				dp[i][2] = min(dp[i-1][1],min(dp[i-1][2],dp[i][1]))+ arr[i][2];
			}
			//cout << dp[i][0] <<' '<<dp[i][1] << ' '<<dp[i][2] <<'\n';
		}

		cout << k++ << ". " << dp[N-1][1] <<'\n';
	}
	return 0;
}