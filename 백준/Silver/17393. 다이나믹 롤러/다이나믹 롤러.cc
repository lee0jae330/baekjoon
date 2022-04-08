#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<long long> ink;
vector<long long> viscosity;

int main(void) {
	fastio();
	int N;
	cin >>N;
	for (int i = 0; i < N; i++) {
		long long num;
		cin >>num;
		ink.push_back(num);
	}

	for (int i = 0; i < N; i++) {
		long long num;
		cin >>num;
		viscosity.push_back(num);
	}

	for (int i = 0; i < N-1; i++) {
		long long num = ink[i];
		auto iter= upper_bound(viscosity.begin(),viscosity.end(),num);
		
		cout << iter-viscosity.begin()-(i+1)<<' ';
	}
	cout <<0<<'\n';
	return 0;
}