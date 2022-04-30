#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int N;
	cin >> N;
	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		if (N % i == 0)
			sum += i;
	}
	sum *= 5;
	sum -= 24;
	cout << sum << '\n';
	return 0;
}