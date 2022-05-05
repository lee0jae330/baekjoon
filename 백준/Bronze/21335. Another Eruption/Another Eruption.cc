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
	unsigned long long N;
	cin >> N;
	double pi = 3.141592;
	cout.precision(12);
	cout << 2 * sqrt((double)N * pi);
	return 0;
}