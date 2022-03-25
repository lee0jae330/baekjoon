#include<iostream>
#include<cmath>

using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;
	double sum = a * 0.229 * 0.324 * 2 + b * 0.297 * 0.42 * 2 + c * 0.21 * 0.297;
	cout << sum << '\n';
	return 0;
}
