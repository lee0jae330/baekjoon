#include<iostream>

using namespace std;

int main(void) {
	int result = 0,T;
	cin >> T;
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		if (num == T)
			result++;
	}
	cout << result << '\n';
	return 0;
}