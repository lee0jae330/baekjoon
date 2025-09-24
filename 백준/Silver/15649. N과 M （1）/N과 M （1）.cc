#include<iostream>
#include<vector>
using namespace std;

int arr[10];

int N, M;

vector<int>v;

void backtrack(int depth) {
	if (depth == M) {
		for (int num : v) {
			cout<< num <<' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!arr[i]) {
			arr[i] = 1;
			v.push_back(i);
			backtrack(depth + 1);
			arr[i] = 0;
			v.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	backtrack(0);
	return 0;
}