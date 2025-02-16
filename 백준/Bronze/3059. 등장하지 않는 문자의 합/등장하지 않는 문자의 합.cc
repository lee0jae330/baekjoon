#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int arr[26];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int sum =0;
		memset(arr, 0, sizeof(arr));
		string str;
		cin >> str;
		for (char c : str) {
			if (!arr[c - 'A']) {
				arr[c - 'A'] = 1;
			}
		}
	
		for (int i = 0; i < 26; i++) {
			if (!arr[i]) {
				sum += ('A' +i);
			}
		}
		cout << sum <<'\n';
	}
	return 0;
}