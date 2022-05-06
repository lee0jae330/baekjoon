#include<iostream>
#include<cmath>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int N, result=0;
	cin >> N;
	while (N) {
		int num = N % 10;
		N /= 10;
		result += pow(num, 5);
	}
	cout << result << '\n';
	return 0;
}