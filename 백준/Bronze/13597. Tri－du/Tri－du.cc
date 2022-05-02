#include<iostream>
#include<algorithm>

using namespace std;


int main(void) {
	int A, B;
	cin >> A >> B;
	if (A == B)
		cout << A << '\n';
	else
		cout << max(A, B) << '\n';
	return 0;
}