#include<iostream>
#include<string>

using namespace std;

int main(void) {
	int standard,mySpeed;
	cin >> standard >> mySpeed;
	int gap = mySpeed - standard;
	int dollar = -1;
	if (gap >= 1 && gap <= 20) {
		dollar = 100;
	}
	else if (gap >= 21 && gap <= 30) {
		dollar = 270;
	}
	else if (gap >= 31) {
		dollar = 500;
	}
	if (dollar == -1) {
		cout << "Congratulations, you are within the speed limit!" << '\n';
	}
	else {
		cout << "You are speeding and your fine is $" << dollar << '.' << '\n';
	}
	return 0;
}