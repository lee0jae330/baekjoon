#include<iostream>
#include<memory.h>
#include<string.h>

using namespace std;

int arr[1000001];

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}


int main(void) {
	fastio();
	memset(arr, -1, sizeof(arr));
	for (int i = 1; i < 1000001; i++) {
		int tmp = i;
		int sol = tmp;
		while (tmp != 0) {
			int mod = tmp % 10;
			sol += mod;
			tmp /= 10;
		}
		if (sol < 1000001) {
			if (arr[sol] == -1)
				arr[sol] = i;
		}
	}
	int N;
	cin >> N;
	if (arr[N] == -1)
		cout << 0 << '\n';
	else
		cout << arr[N] << '\n';
	return 0;
}