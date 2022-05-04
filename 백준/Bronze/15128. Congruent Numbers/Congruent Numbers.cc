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
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	a *= c;
	b *= d*2;
	if (a % b == 0)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
	return 0;
}