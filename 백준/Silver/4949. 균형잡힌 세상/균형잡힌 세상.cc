#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	while (getline(cin, str)) {
		if (str == ".") {
			return 0;
		}
		stack<char>s;
		int flag = 0;

		for (char c : str) {
			if (c == '(') {
				s.push('(');
			}
			else if (c == '[') {
				s.push('[');
			}
			else if (c == ')') {
				if (!s.empty() &&s.top() == '(') {
					s.pop();
				}
				else {
					flag = 1;
					break;
				}
			}
			else if (c == ']') {
				if (!s.empty() && s.top() == '[') {
					s.pop();
				}
				else {
					flag = 1;
					break;
				}
			}
		}

		if (flag || !s.empty()) {
			cout <<"no" <<'\n';
		}
		else {
			cout << "yes" <<'\n';
		}
	}
	return 0;
}