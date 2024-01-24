#include<bits/stdc++.h>

using namespace std;

int N;
vector<int>v;
int dp[300001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	
	
	cin >> N;

	int num = 1;
	while (1) {
		int tmp = num*(num+1)*(num+2) / 6;
		if(tmp > 300000)
			break;
		dp[tmp] = 1;
		v.push_back(tmp);
		//cout << tmp <<'\n';
		num++;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < v.size(); j++) {
			if(v[j]>=i)
				break;
			if(!dp[i])
				dp[i] = 1+dp[i-v[j]];
			else
				dp[i] = min(dp[i],1+dp[i-v[j]]);
		}
	}

	cout << dp[N] <<'\n';

	return 0;
}