#include<iostream>

using namespace std;

int main(void) {
	int A, B,C,D;
	cin >> A >> B >> C >> D;
	if ((A == 8 || A == 9) && B == C && (D == 8 || D == 9))
		cout << "ignore" << '\n';
	else
		cout << "answer" << '\n';
	return 0;
}