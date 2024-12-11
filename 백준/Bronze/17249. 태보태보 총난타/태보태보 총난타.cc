#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	cin >> str;

	int left = 0, right = 0;
	int flag =0;
	for (int i = 0; i < str.length(); i++) {
		if (!flag) {
			if (str[i] == '@') {
				left++;
			}
			else if (str[i] == '(') {
				flag = 1;
			}
		}
		else {
			if (str[i] == '@') {
				right++;
			}
		}
	}
	cout << left << ' '<<right <<'\n';
	return 0;
}