#include<iostream>

using namespace std;

int main(void) {
	int a, b, c;
	char t1, t2;
	cin >> a >> t1 >> b >> t2 >> c;
	if (c == a + b) {
		cout << "YES";
	}
	else
		cout << "NO";
	return 0;
}