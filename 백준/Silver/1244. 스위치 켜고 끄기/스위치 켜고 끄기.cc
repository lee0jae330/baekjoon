#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[102];

int main(void) {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	int M;
	cin >> M;
	while (M--) {
		int s, num;
		cin >> s >> num;
		if (s == 1) {
			for (int i = 1; i * num <= N; i++) {
				if (arr[i*num])
					arr[i*num] = 0;
				else
					arr[i*num] = 1;
			}
		}
		else {
			if (arr[num])
				arr[num] = 0;
			else
				arr[num] = 1;
			int n = 1;
			while (1) {
				int flag = 0;
				int l = num - n, r = num + n;
				if (l >= 1 && r <= N) {
					if (arr[l] == arr[r]) {
						flag = 1;
						if (arr[l]) {
							arr[l] = 0, arr[r] = 0;
						}
						else {
							arr[l] = 1, arr[r] = 1;
						}
					}
				}
				else
					break;
				if (!flag)
					break;
				n++;
			}
		}
	}
	int num = 1;
	for (int i = 1; i <= N; i++) {
		if (num > 20) {
			num = 1;
			cout << '\n';
		}
		cout << arr[i] << ' ';
		num++;

	}
	return 0;
}