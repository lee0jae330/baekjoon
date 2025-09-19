#include<bits/stdc++.h>
#include<set>

using namespace std;

int arr[101][101];
set<int>s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			s.insert(arr[i][j]);
		}
	}

	if (s.size() != N * N) {
		cout << "FALSE" <<'\n';
		return 0;
	}

	int sum = N * (N * N + 1);
	sum /= 2;

	for (int i = 0; i < N; i++) {
		int tmp = 0;
		int tmp2 = 0;
		for (int j = 0; j < N; j++) {
			tmp += arr[i][j];
			tmp2 += arr[j][i];
		}
		if (tmp != sum || tmp2 != sum) {
			cout << "FALSE" << '\n';
			return 0;
		}
	}


	int tmp = 0;
	int tmp2 = 0;
	for (int i = 0; i < N; i++) {
		tmp += arr[i][i];
		tmp2 += arr[i][N-i-1];
		
	}
	if (tmp != sum || tmp2 != sum) {
		cout << "FALSE" << '\n';
		return 0;
	}

	cout << "TRUE" <<'\n';
	return 0;
}