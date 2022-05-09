#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int a, d, k;
	cin >> a >> d >> k;
	int t = k;
	k -= a;
	if (k % d||(t>a&&d<0)||(t<a&&d>0)) {
		cout << 'X' << '\n';
	}
	else {
		int n = 1+ k/d;
		cout << n << '\n';
	}
	return 0;
}