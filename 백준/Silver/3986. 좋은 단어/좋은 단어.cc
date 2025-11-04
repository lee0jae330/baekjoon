#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	int cnt = 0;
	while (N--) {
		string str;
		cin >> str;
		stack<char>s;
		int flag = 0;
		for (char c : str) {
			if (s.empty()) {
				s.push(c);
			}
			else {
				if (s.top() == c) {
					s.pop();
				}
				else {
					s.push(c);
				}
			}
		}
		if (s.empty()) {
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}