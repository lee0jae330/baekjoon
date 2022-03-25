#include<iostream>
#include<cmath>

using namespace std;

int main(void) {
	int  a,b,c;
	cin >> a>>b>>c;

	int num = floor((a + 1) * (b + 1) / (c + 1) - 1);
	cout << num << '\n';
	return 0;
}