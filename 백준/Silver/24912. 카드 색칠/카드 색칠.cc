#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[1000001];
int visited[1000001];

int main(void) {
	fastio();
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		if (!arr[i]) {
			if (i == 0) {
				if (arr[i + 1]==0) {
					arr[i] = 1;
				}
				else {
					if (arr[i + 1] == 1)
						arr[i] = 2;
					else
						arr[i] = 1;
				}
			}
			else if (i == N - 1) {
				if (arr[i - 1] == 1) {
					arr[i] = 2;
				}
				else
					arr[i] = 1;
			}
			else {
				int a = arr[i - 1], b = arr[i + 1];
				if (!b) {
					if (a == 1) {
						arr[i] = 2;
					}
					else
						arr[i] = 1;
				}
				else {
					if (a == b) {
						if (a == 1)
							arr[i] = 2;
						else
							arr[i] = 1;
					}
					else {
						if (a == 1) {
							if (b == 2)
								arr[i] = 3;
							else
								arr[i] = 2;
						}
						else if (a == 2) {
							if (b == 1)
								arr[i] = 3;
							else
								arr[i] = 1;
						}
						else {
							if (b == 1)
								arr[i] = 2;
							else
								arr[i] = 1;
						}
					}
				}
			}
		
		}
	}
	int num = arr[0];
	int flag = 0;
	for (int i = 1; i < N; i++) {
		if (num != arr[i]) {
			num = arr[i];
		}
		else {
			flag = 1;
			break;
		}
	}
	if (!flag) {
		for (int i = 0; i < N; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	else
		cout << -1 << '\n';
	return 0;
}
