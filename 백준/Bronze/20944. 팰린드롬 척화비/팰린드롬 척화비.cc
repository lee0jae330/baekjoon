#include<iostream>
#include<string>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int sum[101];

int main(void) {
	fastio();
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cout << 'a';
	return 0;
}