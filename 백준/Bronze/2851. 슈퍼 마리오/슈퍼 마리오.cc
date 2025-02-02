#include<iostream>
#include<cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int sum;
	
	cin >> sum;
	int sol = sum;
	for (int i = 0; i < 9; i++) {
		int num;
		cin >> num;
		if (abs(100 - sum) >= abs(100 - (sum + num))) {
			sol = sum + num;
		}
		sum+=num;
	}
	cout << sol <<'\n';
	return 0;
}