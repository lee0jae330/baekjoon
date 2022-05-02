#include<iostream>
#include<cmath>
using namespace std;

int main(void) {
	long long N;
	cin >> N;
	double a = sqrt((double)N);
	cout.precision(8);
	cout << 4 * a << '\n';
	return 0;
}