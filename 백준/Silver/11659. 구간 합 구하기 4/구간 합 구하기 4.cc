#include<bits/stdc++.h> 

using namespace std;

int arr[100001];
int dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N,M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	dp[1]=arr[1];

	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i-1] + arr[i];
	}

	while (M--) {
		int i,j;
		cin >> i >> j;
		cout << dp[j] - dp[i-1] <<'\n';
	}
	
	return 0;
}