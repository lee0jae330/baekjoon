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
	long long result = 0;
	long long  tmp = 0;
	for (int i = 1; i <= N - 2; i++) {
		tmp += i;
		result += tmp;
	}
	cout << result << '\n';
	cout << 3 << '\n';
	
	return 0;
}