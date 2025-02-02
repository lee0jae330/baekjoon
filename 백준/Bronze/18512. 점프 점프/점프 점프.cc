#include<iostream>

using namespace std;

int arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int X, Y, P1, P2;
	cin >> X >> Y >> P1 >> P2;

	for (int i = 0; X * i + P1 <= 100000; i++) {
		arr[X * i + P1] = 1;
	}

	for (int i = 0; Y * i + P2 <= 100000; i++) {
		if (arr[Y * i + P2]) {
			cout << Y * i + P2 << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;
}