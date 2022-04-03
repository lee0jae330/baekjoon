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
	long long N;
	cin >> N;
	if (N == 1||N==2)
		cout << "koosaga" << '\n';
	else {
		if (N % 2 == 0) { //짝수
			N /= 2;
			for (long long i = 2; i <= sqrt(N); i++) {
				if (N % i == 0) {
					cout << "koosaga" << '\n';
					return 0;
				}
			}
			cout << "cubelover" << '\n';

		}
		else {
			int cnt = 0;
			int num = 0;
			for (long long i = 2; i <= sqrt(N); i++) {
				if (N % i == 0) {
					cnt++;
					num = i;
				}
				if (cnt > 1) {
					break;
				}
			}
			if (cnt != 1)
				cout << "koosaga" << '\n';
			else {
				if (sqrt(N / num) == num)
					cout << "koosaga" << '\n';
				else
					cout << "cubelover" << '\n';

			}
		}
	}
	return 0;
}