#include<iostream>
#include<deque>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string cmd;
		cin >> cmd;
		int N;
		cin >> N;
		string input;
		cin >> input;
		input.erase(0, 1);
		input.erase(input.length() - 1, 1);
		deque<string>dq;
		int pos;
		string tmp = "";
		for (char c : input) {
			if (c >= '0' && c <= '9') {
				tmp += c;
			}
			else {
				dq.push_back(tmp);
				tmp = "";
			}
		}
		if (tmp != "") {
			dq.push_back(tmp);
		}


		bool isReverse = 0;
		int flag = 0;
		for (char c : cmd) {
			if (c == 'R') {
				isReverse = !isReverse;
			}
			else {
				if (dq.empty()) {
					flag = 1;
					break;
				}

				if (!isReverse) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
		}
		if (flag) {
			cout << "error" << '\n';
		}
		else {
			cout << '[';
			if (!isReverse) {
				for (int i = 0; i < dq.size(); i++) {
					cout << dq[i];
					if (i != dq.size() - 1) {
						cout << ',';
					}
				}
			}
			else {
				for (int i = dq.size() - 1; i >= 0; i--) {
					cout << dq[i];
					if (i != 0) {
						cout << ',';
					}
				}
			}
			cout << ']' << '\n';
		}
	}
}
