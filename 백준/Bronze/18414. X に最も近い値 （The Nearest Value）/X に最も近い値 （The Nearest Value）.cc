#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int X, L, R;
	cin >> X >> L >> R;
	int gap = 1000000;
	int sol = -1;
	for (int i = L; i <= R; i++) {
		if (gap > abs(X - i)) {
			gap = abs(X - i);
			sol = i;
		}
	}
	cout << sol << '\n';;
	return 0;
}