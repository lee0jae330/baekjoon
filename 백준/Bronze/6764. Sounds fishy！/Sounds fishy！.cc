#include<iostream>
#include<algorithm>

using namespace std;

int arr[5];

int main(void) {
	for (int i = 0; i < 4; i++)
		cin >> arr[i];
	if (arr[0] < arr[1] && arr[1] < arr[2] && arr[2] < arr[3]) {
		cout << "Fish Rising" << '\n';
	}
	else if (arr[0] > arr[1] && arr[1] > arr[2] && arr[2] > arr[3]) {
		cout << "Fish Diving" << '\n';
	}
	else if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3]) {
		cout << "Fish At Constant Depth" << '\n';
	}
	else {
		cout << "No Fish" << '\n';
	}
	return 0;
}