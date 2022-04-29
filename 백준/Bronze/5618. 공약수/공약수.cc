#include<iostream>
#include<algorithm>

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
	if (N == 2) {
		int a, b,mn;
		cin >> a >> b;
		mn = min(a, b);
		for (int i = 1; i <= mn; i++) {
			if (a % i == 0 && b % i == 0)
				cout << i << '\n';
		}
	}
	else {
		int a, b, c, mn;
		cin >> a >> b >> c;
		mn = min(a, b);
		mn = min(mn, c);
		for (int i = 1; i <= mn; i++) {
			if (a % i == 0 && b % i == 0 && c % i == 0)
				cout << i << '\n';
		}
	}
	return 0;
}