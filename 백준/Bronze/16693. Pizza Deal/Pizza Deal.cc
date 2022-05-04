#define _USE_MATH_DEFINES

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
	double a, b;
	cin >> a >> b;
	double n1 = a / b;
	cin >> a >> b;
	double n2 = a * a * M_PI / b;
	if (n1 > n2)
		cout << "Slice of pizza" << '\n';
	else
		cout << "Whole pizza" << '\n';
	return 0;
}