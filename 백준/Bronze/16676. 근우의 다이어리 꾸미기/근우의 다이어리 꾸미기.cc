#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	if (N <= 10) {
		cout << 1;
	}
	else if (N <= 110) {
		cout << 2;
	}
	else if (N <= 1110) {
		cout << 3;
	}
	else if (N <= 11110) {
		cout << 4;
	}
	else if (N <= 111110) {
		cout << 5;
	}
	else if (N <= 1111110) {
		cout << 6;
	}
	else if (N <= 11111110) {
		cout << 7;
	}
	else if (N <= 111111110) {
		cout << 8;
	}
	else {
		cout << 9;
	}
	return 0;
}