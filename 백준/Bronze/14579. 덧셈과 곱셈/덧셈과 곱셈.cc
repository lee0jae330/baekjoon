#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	long long result = 1;
	long long a, b;
	cin >> a >> b;
	long long sum = 0;
	for (long long i = 1; i <= a; i++)
		sum += i;
	sum %= 14579;
	result *= sum;
	sum %= 14579;
	for (long long i = a + 1; i <= b; i++) {
		sum += i;
		sum %= 14579;
		result *= sum;
		result %= 14579;

	}
	cout << result << '\n';
	return 0;
}