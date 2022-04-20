#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

deque<int>dq;

int main(void) {
	int K;
	cin >> K;
	K++;
	while (K > 1) {
		int num = K % 2;
		K /= 2;
		dq.push_front(num);
	}
	while (!dq.empty()) {
		if (dq.front() == 0)
			cout << 4;
		else
			cout << 7;
		dq.pop_front();
	}
	return 0;
}