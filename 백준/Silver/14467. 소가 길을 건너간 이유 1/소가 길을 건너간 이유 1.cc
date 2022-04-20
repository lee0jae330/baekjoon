#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[11];

int main(void) {
	fastio();
	for (int i = 0; i < 11; i++)
		arr[i] = -1;
	int N;
	cin >> N;
	int result = 0;
	while (N--) {
		int cow, loc;
		cin >> cow >> loc;
		if (arr[cow] == -1)
			arr[cow] = loc;
		else {
			if (arr[cow]&&!loc) {
				arr[cow] = loc;
				result++;
			}
			else if (!arr[cow] && loc) {
				arr[cow] = loc;
				result++;
			}
		}
	}
	cout << result << '\n';
	return 0;
}