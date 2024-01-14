#include<bits/stdc++.h>

using namespace std;

int arr[101];
int dp[100001];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,K;
	cin >> N >>K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	dp[0] = 1; //0원을 만드는 가짓수는 하나도 사용을 안하면 돼서 1가지

	for (int i = 1; i <= N; i++) {
		for (int j = arr[i]; j <= K; j++) {
			 dp[j]+=dp[j-arr[i]];
		}
	}

	cout << dp[K] <<'\n';
	return 0;
}