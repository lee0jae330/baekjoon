#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main(void) {
	fastio();
	int N, M, K;
	cin >> N >> M >> K;
	int cnt = 0;
	if (N / 2 < M) {
		while (N / 2 < M) {
			cnt++;
			M--;
		}
		K -= cnt;
		int i = 1;
		while (K-->0) {
			if (i % 3 == 1)
				N--;
			else if (i % 3 == 2)
				N--;
			else
				M--;
			i++;
		}
		if (N/2 > M)
			cout << M << '\n';
		else
			cout << N / 2 << '\n';
	}
	else if (N / 2 > M) {
		int tmp = 2 * M;
		int gap = N - 2 * M;
		N = tmp;
		K -= gap;
		if (K <= 0) {
			cout << M << '\n';
		}
		else {
			int i = 0;
			while (K > 0) {
				if (i % 2) {
					K--;
					M--;
				}
				else {
					K -= 2;
					N -= 2;
				}
				i++;
			}
			if (N / 2 >= M)
				cout << M << '\n';
			else
				cout << N / 2 << '\n';
		}

	}
	else {
		int i = 0;
		while (K > 0) {
			if (i % 2) {
				K--;
				M--;
			}
			else {
				K -= 2;
				N -= 2;
			}
			i++;
		}

		if (N / 2 >= M)
			cout << M << '\n';
		else
			cout << N / 2 << '\n';
	}
	return 0;
}