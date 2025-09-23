#include<iostream>

using namespace std;

int arr[2000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int front = 0;
	int rear = 0;


	int N;
	cin >> N;
	while (N--) {
		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int n;
			cin >> n;
			arr[rear++] = n;
		}
		else if (cmd == "front") {
			if (front == rear && !arr[front]) {
				cout << -1 <<'\n';
			}
			else {
				cout << arr[front] <<'\n';
			}
		} else if (cmd == "back") {
			if (front == rear && !arr[front]) {
				cout << -1 << '\n';
			}
			else {
				cout << arr[rear-1] << '\n';
			}
		}
		else if (cmd == "size") {
			cout << rear -front <<'\n';
		}
		else if (cmd == "empty") {
			int result = (front == rear&& !arr[front]) ? 1 : 0;
			cout << result  <<'\n';
		}
		else {
			if (front == rear && !arr[front]) {
				cout << -1 << '\n';
			}
			else {
				cout << arr[front++] <<'\n';
			}
		}
	}
}