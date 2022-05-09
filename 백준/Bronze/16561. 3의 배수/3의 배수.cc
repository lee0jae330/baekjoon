#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int N,cnt=0;
	cin >> N;
	for (int i = 3; i < N; i += 3) {
		for (int j = i; j < N; j += 3) {
			for (int k = j; k < N; k += 3) {
				if (i + j + k == N) {
					if (i == j && j == k)
						cnt++;
					else if (i == j || i == k || j == k)
						cnt += 3;
					else
						cnt += 6;
				}
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}