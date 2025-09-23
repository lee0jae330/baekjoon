#include<iostream>
#include<deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	deque<int>dq;

	int N;
	cin >> N;

	while (N--) {
		string cmd;
		cin >> cmd;
		if(cmd =="push_back") {
			int n;
			cin >> n;
			dq.push_back(n);
		}
		else if (cmd == "push_front") {
			int n;
			cin >> n;
			dq.push_front(n);
		}
		else if (cmd == "pop_back") {
			if (dq.empty()) {
				cout << - 1 <<'\n';
			}
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (cmd == "pop_front") {
			if (dq.empty()) {
				cout << -1 <<'\n';
			}
			else {
				cout << dq.front() <<'\n';
				dq.pop_front();
			}
		}
		else if (cmd == "size") {
			cout << dq.size()<<'\n';
		}
		else if (cmd == "empty") {
			cout << (dq.empty() ?1:0 ) <<'\n';
		}
		else if (cmd == "front") {
			if (dq.empty()) {
				cout << -1 <<'\n';
			}
			else {
				cout << dq.front() <<'\n';
			}
		}
		else {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.back() << '\n';
			}
		}
	}

}