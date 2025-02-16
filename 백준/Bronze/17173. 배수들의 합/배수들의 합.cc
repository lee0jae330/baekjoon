#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N,M;
vector<int>v;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M;
	v.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> v[i];
	}

	int sum = 0;

	for (int i = 1; i <= N; i++) {
		for (int num : v) {
			if (i % num == 0) {
				sum += i;
				break;
			}
		}
	}
	cout << sum <<'\n';
	return 0;
}