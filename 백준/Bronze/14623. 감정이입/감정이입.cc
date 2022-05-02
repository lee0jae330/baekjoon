#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

string ADD(string s1, string s2) {
	if (s1.length() < s2.length()) {
		swap(s1, s2);
	}
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	int len = s2.length();
	int flag = 0;
	string result;
	for (int i = 0; i < len; i++) {
		int num = s1[i] - '0' + s2[i] - '0';
		num += flag;
		flag = 0;
		if (num > 1) {
			num %= 2;
			flag = 1;
		}
		result += '0' + num;
	}
	for (int i = len; i < s1.length(); i++) {
		int num = s1[i] - '0';
		num += flag;
		flag = 0;
		if (num > 1) {
			num %= 2;
			flag = 1;
		}
		result += '0' + num;
	}
	if (flag)
		result += '1';
	reverse(result.begin(), result.end());
	return result;
}

int main(void) {
	fastio();
	string s1, s2;
	cin >> s1 >> s2;
	string result = "0";
	if (s1.length() < s2.length())
		swap(s1, s2);
	int len = s2.length();
	for (int l = 0; l < len; l++) {
		char c = s2[len - 1 - l];
		string tmp;
		if (c == '0') {
			for (int j = 0; j < s1.length(); j++)
				tmp += '0';
		}
		else {
			tmp = s1;
		}
		for (int j = 0; j < l; j++)
			tmp += '0';
		result = ADD(result, tmp);
	}
	cout << result << '\n';
	return 0;
}