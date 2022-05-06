#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	long long N;
	cin >> N;
	N++;
	long long result = (3 * N * N - N) / 2;
	result %= 45678;
	cout << result << '\n';
	return 0;
}