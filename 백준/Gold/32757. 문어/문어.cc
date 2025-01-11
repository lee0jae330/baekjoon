#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	if (N <= K) {
		cout << 0 << '\n';
	}
	else if (N % 2 == 0) {
		cout << N<<'\n';
	}
	else if (K == 2 || K+1 == N) {
		cout << N <<'\n';
	}
	else {
		cout << (K%2 == 0 ? N : N - 1) << '\n';
	}
	return 0;
}