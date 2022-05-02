#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int A, B;
	cin >> A >> B;
	double M = (double)(B - A) / 400;
	double result = 1. / (1. + pow(10, M));
	cout.precision(12);
	cout << result << '\n';
	return 0;
}