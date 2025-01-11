#include<iostream>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	cout << (N<=K ? 0 : (N%2==0 ? N :(K%2==0?N:N-1)));
	return 0;
}