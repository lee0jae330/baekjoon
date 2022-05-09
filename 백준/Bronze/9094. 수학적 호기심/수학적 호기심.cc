#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		int cnt = 0;
		for (int a = 1; a < n-1; a++) {
			for (int b = a + 1; b < n; b++) {
				int flag = 0;
				int num = a * a + b * b + m;
				if (num % (a * b))
					flag = 1;
				if (!flag) {
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}