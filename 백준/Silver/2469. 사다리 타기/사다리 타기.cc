#include<iostream>
#include<string>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

char arr[1001][27];
int mid[27];
int mid2[27];
int last[27];
int check[27];

int main(void) {
	fastio();
	int K;
	cin >> K;
	int N;
	cin >> N;
	for (int i = 0; i < K; i++) {
		char c;
		cin >> c;
		last[i] = c - 'A';
	}
	int blank;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K - 1; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '?')
				blank = i;
		}
	}
	
	for (int k = 0; k < K; k++) {
		int tmp = k;
		for (int i = 0; i < blank; i++) {
			if (tmp == 0) {
				if (arr[i][tmp] == '-')
					tmp++;
			}
			else if (tmp == K - 1) {
				if (arr[i][tmp - 1] == '-')
					tmp--;
			}
			else {
				if (arr[i][tmp - 1] == '-')
					tmp--;
				else if (arr[i][tmp] == '-')
					tmp++;
			}
		}
		mid[tmp] = k;
	}

	for (int k = 0; k < K; k++) {
		int tmp = k;
		for (int i = N - 1; i > blank; i--) {
			if (tmp == 0) {
				if (arr[i][tmp] == '-')
					tmp++;
			}
			else if (tmp == K - 1) {
				if (arr[i][tmp - 1] == '-')
					tmp--;
			}
			else {
				if (arr[i][tmp - 1] == '-')
					tmp--;
				else if (arr[i][tmp] == '-')
					tmp++;
			}
		}
		mid2[tmp] = last[k];
	}
	
	string result;
	int flag = 0;
	for (int k = 0; k < K - 1; k++) {
		if (mid[k] == mid2[k]) {
			result += '*';
		}
		else {
			int ta = mid[k], tb = mid[k + 1];
			if (tb == mid2[k] && ta == mid2[k + 1]) {
				result += '-';
				swap(mid[k], mid[k + 1]);
			}
			else {
				result += '*';
			}
		}
	}
	for (int i = 0; i < K; i++) {
		if (mid[i] != mid2[i]) {
			flag = 1;
			break;
		}
	}
	if (flag) {
		for (int i = 0; i < K - 1; i++)
			cout << 'x';
		cout << '\n';
	}
	else {
		cout << result << '\n';
	}
	/*for (int i = 0; i < K; i++)
		cout << mid[i] << ' ';
	cout << '\n';
	for (int i = 0; i < K; i++)
		cout << mid2[i] << ' ';
	cout << '\n';*/
	return 0;
}