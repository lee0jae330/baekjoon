#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int arr[5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	string str;
	cin >> str;
	for (char c : str) {
		if (c == 'u') {
			arr[0]++;
		}
		else if (c == 'o') {
			arr[1]++;
		}
		else if (c == 's') {
			arr[2]++;
		}
		else if (c == 'p') {
			arr[3]++;
		}
		else if (c == 'c') {
			arr[4]++;
		}
	}
	cout << *min_element(arr, arr+5) <<'\n';
	return 0;
}