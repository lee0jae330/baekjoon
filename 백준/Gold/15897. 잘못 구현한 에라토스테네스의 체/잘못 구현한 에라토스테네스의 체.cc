#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	int N;
	cin >> N;
	long long sol = N;
	for (long long i = 2, j = 0; i < N; i = j + 1) {
		j = (N - 1) / ((N - 1) / i);
		long long tmp = 1 + (N - 1) / i;
		sol += (j - i + 1) * tmp;
	}
	if (N != 1)
		sol++;
	cout << sol << '\n';
	return 0;
}