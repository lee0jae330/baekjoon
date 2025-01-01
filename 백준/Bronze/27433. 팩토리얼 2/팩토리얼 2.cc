#include<iostream>

using namespace std;

unsigned long long fact(int n) {
	if (!n) {
		return 1;
	}
	return n * fact(n-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin>> N;
	cout << fact(N) <<'\n';
	return 0;

}