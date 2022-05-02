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
	double L;
	cin >> L;
	double result = L * L * sqrt(3) / 4;
	cout.precision(15);
	cout << result << '\n';
	return 0;
}