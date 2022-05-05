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
	long long a, b,c;
	cin >> a >> b;
	long long sum = a * b;
	cin >> a >> b;
	sum += a * b;
	cin >> a >> b >> c;
	sum *= a * b * c;
	cout << sum << '\n';
	return 0;
}