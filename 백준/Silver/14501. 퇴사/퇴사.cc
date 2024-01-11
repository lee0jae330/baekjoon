#include<bits/stdc++.h>

using namespace std;

int arr[16];
int t[16];
int dp[16];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int  N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> t[i] >> arr[i];
		if (t[i] + i <= N+1) {
			dp[i] = arr[i];
		}
	}

	int sol = 0; 
	for (int i = 1; i <= N; i++) {
		for(int j=1;j<i;j++) {
			if (t[j] + j <= i) {
				if (i + t[i] <= N+1) {
					dp[i] = max(dp[j]+arr[i],dp[i]);
				}
			}
		}
		sol = max(sol,dp[i]);
	}
	cout << sol <<'\n';
	return 0;
}