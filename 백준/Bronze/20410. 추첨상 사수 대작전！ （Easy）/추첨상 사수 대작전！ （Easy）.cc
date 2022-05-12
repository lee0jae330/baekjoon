#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int m, seed, x1, x2;
	cin >> m >> seed >> x1 >> x2;
	for (int a = 0;; a++) {
		for (int c = 0;c<m; c++) {
			int num = seed * a + c;
			int tmp = x1 * a + c;
			
			if (num % m == x1&&tmp%m==x2) {
					cout << a << ' ' << c << '\n';
					return 0;
			}
		}
	}
}