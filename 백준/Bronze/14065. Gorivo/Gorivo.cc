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
	double mile = 1.609344;
	double x;
	cin >> x;
	mile *= x;
	double result = 3.785411784 / mile * 100;
	cout.precision(12);
	cout << result << '\n';
	return 0;
}