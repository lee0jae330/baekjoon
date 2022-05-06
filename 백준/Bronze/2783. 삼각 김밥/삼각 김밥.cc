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
	double a, b;
	cin >> b >> a;
	a = b / a;
	int N;
	cin >> N;
	while (N--) {
		double x, y;
		cin >> y >> x;
		a = min(a, y / x);
	}
	cout << fixed;
	cout.precision(2);
	cout << a*1000. << '\n';
	return 0;
}