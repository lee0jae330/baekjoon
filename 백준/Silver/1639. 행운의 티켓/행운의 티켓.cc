#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;
	int len = str.length();
	int sol = 0;
	for (int i = 2; i <= len; i += 2) {
		for (int j = 0; j <= len - i; j++) {
			int n = i / 2;
			string f = str.substr(j, n);
			string b = str.substr(j + n, n);
			int num1 = 0, num2 = 0;
			for (char c : f) {
				num1 += (c - '0');
			}
			for (char c : b) {
				num2 += (c - '0');
			}
			if (num1 == num2) {
				sol = max(sol, i);
			}
		}
	}
	cout << sol << '\n';
	return 0;
}