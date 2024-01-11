#include<bits/stdc++.h>

using namespace std;

long long dp1[1000002]; //양수
long long dp2[1000002]; //음수
long long mod = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	dp1[0] = 0;
	dp1[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		dp1[i] = (dp1[i-1] + dp1[i-2]) % mod;
	}

	dp2[1000000] = 0;
	dp2[999999] = 1;

	for (int i = -2; i >= -1e6; i--) {
		dp2[1000000+i] = ( dp2[1000000+i+1] + dp2[1000000 + i +2] ) % mod;
	}
	
	int N ;
	cin >> N;
	if (N >= 0) {
		if (N == 0) {
			cout << 0<<'\n';
		}
		else {
			cout << 1 <<'\n';
		}
		cout << dp1[N];
	}
	else {
		if ((N+1000000) % 2) {
			cout << 1 <<'\n';
		}
		else {
			cout << -1 <<'\n';
		}
		cout << dp2[N+1000000];
	}
	return 0;
}