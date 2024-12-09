#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	int zero = 0, one =0;
	cin >> s;

	char c  = s[0];
	(s[0] == '0') ? zero++ : one++;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] != c) {
			c = s[i];
			s[i] == '0' ? zero++ : one++;
		}
	}

	cout << min(zero,one) << '\n';
	return 0;

}