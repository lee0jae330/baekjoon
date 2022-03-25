#include<iostream>
#include<cmath>

using namespace std;

int main(void) {
	int sum = 0, a;
	for (int i = 0; i < 6; i++) {
		cin >> a;
		sum += a;
	}
	cout << sum * 5 << '\n';
	return 0;
}