#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int comb[10001][5001];


int N, M;

int sol(int x) {
	int count_2 = 0;
	int sum =0;
	while (1) {
		if(N-M*count_2<0)
			break;
		int count_1=N-M*count_2;
		int idx = (count_1<=count_2) ? count_1 : count_2;
		sum += comb[count_1+count_2][idx];
		sum%=mod;
		count_2++;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	comb[0][0] = 1;

	for (int i = 1; i <= 10000; i++) {
		comb[i][0] = 1;
	}

	for (int i = 2; i <= 10000; i++) {
		for (int j = 1; j <= i/2; j++) {
		int idx1 = i-1 - (j-1);
		int k1 = (idx1 <= (j-1)) ? idx1 : j-1;
		idx1= i-1-j;
		int k2 = (idx1 <= j) ? idx1 : j;
			comb[i][j] = comb[i-1][k1]+comb[i-1][k2];
			comb[i][j]%=mod;
		}
	}

	cin >> N >> M;
	cout << sol(M) <<'\n';
	return 0;
}