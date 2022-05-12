#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main(void) {
	fastio();
	while (1) {
		string s;
		cin >> s;
		if (s.length() == 1 && s[0] == '0')
			break;
		int num=0;
		string ts = s;
		for (int i = 0; i < s.length(); i++) {
			num += s[i] - '0';
		}
		while (num >9) {
			int tmp = num;
			num = 0;
			while (tmp) {
				num += (tmp % 10);
				tmp /= 10;
			}
		}
		cout << num << '\n';
	}
	return 0;
}