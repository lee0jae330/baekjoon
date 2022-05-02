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
	long long N;
	cin >> N;
	double a = sqrt((double)N) * 4;
	cout.precision(12);
	cout << a << '\n';
	return 0;
}