#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[1001];

int main(void) {
	fastio();
	int cnt = 1,flag=0;
	for (int i = 0; i < 1001; i++) {
		if (flag == cnt) {
			cnt++;
			flag = 0;
		}
		arr[i] = cnt;
		flag++;
	}
	
	int A, B;
	cin >> A >> B;
	long long result = 0;
	for (int i = A - 1; i < B; i++) {
		result += arr[i];
	}
	cout << result << '\n';
	return 0;
}