#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdlib>
#include<time.h>
#include<algorithm>
#include<string>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	srand((unsigned int)(time(NULL)));
	fastio();

	int i=101;

	for (int t = 0; t < 1; t++) {
		cout << i <<'\n';
		for (int j = 0; j < i; j++) {
			cout << 0<<'\n';
		}
		cout << 1 <<'\n';
		cout << 0 <<' '<<1 <<'\n';
		i++;
	}

	return 0;
}