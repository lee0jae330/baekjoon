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
	if (s1.length() < s2.length())
		swap(s1, s2);	
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	string result;
	int flag = 0;
	for (int i = 0; i < s2.length(); i++) {
		int c1 = s1[i]-'0', c2 = s2[i]-'0';
		int num = c1 + c2;
		if (i == 0) {
			if (num > 1) {
				flag = 1;
				num %= 2;
			}
			result += (num + '0');
		}
		else {
			if (flag) {
				num += flag;
				flag = 0;
			}
			if (num > 1) {
				flag = 1;
				num %= 2;
			}
			result += (num + '0');
		}
	}
	if (s1.length() > s2.length()) {
		for (int i = s2.length(); i < s1.length(); i++) {
			int num = s1[i] - '0';
			if (flag) {
				num += flag;
				flag = 0;
			}
			if (num > 1) {
				flag = 1;
				num %= 2;
			}
			result += (num + '0');
		}
	}
	if (flag)
		result += '1';
	reverse(result.begin(), result.end());
	return result;
}

int main(void) {
	fastio();
	int T=1;
	
	while (T--) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s1[0] == '0') {
			int flag = 0;
			int len = s1.length();
			for (int i = 0; i < len; i++) {
				if (s1[i] != '0') {
					flag = 1;
					s1= s1.substr(i, len - i);
					break;
				}
			}
			if (!flag) {
				s1 = s1.substr(0, 1);
			}
		}
		if (s2[0] == '0') {
			int flag = 0;
			int len = s2.length();
			for (int i = 0; i < len; i++) {
				if (s2[i] != '0') {
					flag = 1;
					s2= s2.substr(i, len - i);
					break;
				}
			}
			if (!flag) {
				s2 = s2.substr(0, 1);
			}
		}
		cout << ADD(s1, s2) << '\n';
	}
	return 0;
}