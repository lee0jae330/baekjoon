#include<iostream>
#include<string>

using namespace std;

int main(void) {
	string s;
	cin >> s;
	for (int i = 0; i < 3; i++) {
		if (s[i] != '5') {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
	return 0;
}