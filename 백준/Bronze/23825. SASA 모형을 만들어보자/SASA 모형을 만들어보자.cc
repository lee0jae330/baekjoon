#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	int a, b;
	cin >> a >> b;
	a = min(a, b);
	cout << a / 2 << '\n';
	return 0;
}