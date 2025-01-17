#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s;
	while (1) {
		getline(cin, s);
		if (cin.eof()) {
			return 0;
		}
		cout << s <<'\n';
	}
}