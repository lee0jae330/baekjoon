#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;
	stack<pair<char, int>>s;
	for (char c : str) {
		if (s.empty()) {
			if (c == '(' || c == '[') {
				s.push({ c, 0 });
			}
			else {
				cout << 0 << '\n';
				return 0;
			}
		}
		else {
			if (c == '(' || c == '[') {
				s.push({ c, 0 });
			}
			else {
				char start = c == ')' ? '(' : '[';
				int tmp = c == ')' ? 2 : 3;
				int num = 0;
				int flag = 0;
				while (!s.empty()) {
					auto [ch, n] = s.top();
					s.pop();
					if (ch == ' ') {
						num += n;
					}
					else if (ch == start) {
						if (!num) {
							s.push({ ' ', tmp });
						}
						else {
							s.push({ ' ', tmp * num });
						}
						flag = 1;
						break;
					}
					else {
						cout << 0 << '\n';
						return 0;
					}
				}
				if (!flag) {
					cout << 0 << '\n';
					return 0;
				}
			}
		}
	}
	long long sol = 0;
	while (!s.empty()) {
		auto [ch, n] = s.top();
		s.pop();
		if (ch != ' ') {
			cout << 0 << '\n';
			return 0;
		}
		sol += n;
	}
	cout << sol << '\n';
	return 0;
}