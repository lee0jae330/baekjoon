#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[16];

int main(void) {
	fastio();
	arr[1]=2;
	for (int i = 2; i < 16; i++) {
		arr[i]=arr[i-1]*3;
	}
	int N;
	cin >> N;
	cout <<arr[N]<<'\n';
	return 0;
}