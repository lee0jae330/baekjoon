#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int prime[10001];

vector<int> v;
vector<int> sol;
int main(void) {
	fastio();
	prime[1]=1;
	for (int i = 2; i < 10001; i++) {
		if(prime[i])
			continue;
		for (int j = i+i; j < 10001; j += i) {
			prime[j]=1;
		}
	}
	int N,M;
	cin >> N>>M;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	vector<int> comb;
	for (int i = 0; i < M; i++) {
		comb.push_back(1);
	}
	for (int i = 0; i < N - M; i++) {
		comb.push_back(0);
	}
	sort(comb.begin(),comb.end());
	
	do {
		int sum=0;
		for (int i = 0; i < N; i++) {
			if (comb[i]) {
				sum+=v[i];
			}
		}
		if (!prime[sum]) {
			prime[sum]=1;
			sol.push_back(sum);
		}
	}while(next_permutation(comb.begin(),comb.end()));
	sort(sol.begin(),sol.end());
	if(sol.size()==0)
		cout <<-1<<'\n';
	for(int i=0;i<sol.size();i++)
		cout << sol[i]<<' ';
	cout <<'\n';
	return 0;
}
