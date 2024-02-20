#include<iostream>
#include<stack>
#include<string>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

stack<string>s;

void rec(string str) {
	s.push(str);
	if (str.length() == 1)
		return;
	if (str.length() > 2) {
		if (str[0] > str[1]) {
			string tmp = str.substr(2);
			rec(str[1] + tmp);
		}
		else {
			string tmp;
			tmp += str[0];
			int flag = 0;
			for (int i = 1; i < str.length()-1; i++) {
				if (flag) {
					tmp += str[i];
					continue;
				}
				if (str[i] <= str[i + 1])
					tmp += str[i];
				else
					flag = 1;
				
			}
			if (flag)
				tmp += str[str.length() - 1];
			rec(tmp);
		}
	}
	else {
		if (str[0] <= str[1]) {
			rec(str.substr(0, 1));
		}
		else {
			rec(str.substr(1, 1));
		}
	}
}

int main(void) {
	fastio();
	string str;
	cin >> str;
	rec(str);
	while (!s.empty()) {
		cout << s.top()<<'\n';
		s.pop();
	}
	return 0;
}