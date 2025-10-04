#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;

	int flag = 0;

	int sum = 0;
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] == '*') {
			if (i % 2) {
				flag = 1;
			}
			continue;
		}

		if (i % 2) {
			sum += (str[i] - '0') * 3;
		}
		else {
			sum += (str[i] - '0');
		}
	}

	int tmp = 10 - (str[str.size() - 1] - '0');
	tmp -= (sum % 10);


	if (flag) {

		while (tmp % 3 || tmp < 0) {
			tmp += 10;
		}

		cout << (tmp / 3 >= 10 ? (tmp / 3) - 10 : tmp / 3) << '\n';
	}
	else {
		if (tmp < 0) {
			tmp += 10;
		}
		if (tmp >= 10) {
			tmp -= 10;
		}
		cout << tmp << '\n';
	}
	return 0;
}