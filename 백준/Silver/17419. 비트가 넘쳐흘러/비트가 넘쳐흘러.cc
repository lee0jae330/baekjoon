#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}



int main(void) {
	fastio();
	int cnt = 0, N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char num;
		cin >> num;
		if (num=='1')
			cnt++;
	}
	cout << cnt << '\n';
	return 0;
}