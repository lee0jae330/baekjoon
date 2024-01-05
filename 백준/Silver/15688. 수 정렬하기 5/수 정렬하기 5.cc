#include<bits/stdc++.h>

using namespace std;

int arr[2000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr[num+1000000]++;
	}

	for (int i = 0; i < 2000001; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << i-1000000 <<'\n';
		}
	}
	return 0;
}