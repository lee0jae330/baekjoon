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
	long long a;
	cin >> a;
	cout.precision(12);
	cout << sqrt((double)a) * 4;
	return 0;
}