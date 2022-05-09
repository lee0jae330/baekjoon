#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[6] = { 0,1,2,6,24,120 };

int main(void) {
	fastio();
	while (1) {
		int N;
		cin >> N;
		if (!N)
			break;
		int num = 1;
		int result = 0;
		while (N) {
			int tmp = N % 10;
			tmp *= arr[num++];
			result += tmp;
			N /= 10;
		}
		cout << result << '\n';
	}
	return 0;
}