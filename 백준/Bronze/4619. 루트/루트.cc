#include<iostream>
#include<cstdlib>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	while (1) {
		int B, N;
		cin >> B >> N;
		if (!B && !N)
			break;
		int sol = 0, gap=1e8;

		for (int a = 1; a <= 1000000; a++) {
			int num = 1;
			for (int j = 0; j < N; j++) {
				num *= a;
			}
			if (num < B) {
				if (gap > abs(B - num)) {
					sol = a;
					gap = abs(B - num);
				}
			}
			else {
				if (gap > abs(B - num)) {
					sol = a;
				}
				break;
			}
		}

		cout << sol << '\n';
	}
	return 0;
}