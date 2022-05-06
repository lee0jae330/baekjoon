#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void print1(int N) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < N; j++) {
			for(int k=0;k<N;k++)
				cout << '@';
			cout << '\n';

		}
	}
		
}

void print2(int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N * 5; j++)
			cout << '@';
		cout << '\n';
	}
}

int main(void) {
	fastio();
	int N;
	cin >> N;
	print1(N);
	print2(N);
	return 0;
}