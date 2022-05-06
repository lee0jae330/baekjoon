#include<iostream>
#include<cmath>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main(void) {
	double k;
	cin >> k;
	double sum = 25;
	k *= 0.01;
	sum += k;
	if (sum < 100.)
		sum = 100;
	else if (sum > 2000.)
		sum = 2000;
	cout << fixed;
	cout.precision(2);
	cout << sum << '\n';
	return 0;
}