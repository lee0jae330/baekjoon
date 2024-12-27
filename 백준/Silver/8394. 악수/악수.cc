#include<iostream>

using namespace std;

const int SIZE = (int)1e7+1;
int dp[SIZE];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	dp[1]=1;
	dp[2]=2;
	for (int i = 3; i < SIZE; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10;
	}
	
	int N;
	cin >> N;
	cout << dp[N] << '\n';
	return 0;
}