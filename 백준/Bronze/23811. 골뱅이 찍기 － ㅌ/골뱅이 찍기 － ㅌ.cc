#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void print1(int N) {
	for (int x = 0; x < N; x++) {
		for (int i = 0; i < N * 5; i++)
			cout << '@';
		cout << '\n';
	}
	
}

void print2(int N) {
	for (int x = 0; x < N; x++) {
		for (int i = 0; i < N; i++)
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
	print1(N);
	print2(N);
	print1(N);
	return 0;
}