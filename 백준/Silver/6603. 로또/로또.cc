#include<bits/stdc++.h>

using namespace std;

int N;
vector<int>v;
vector<int>arr;
int visited[14];

void backtrack(int idx) {
	if (arr.size() == 6) {
		for (int num : arr) {
			cout << num << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i < N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			arr.push_back(v[i]);
			backtrack(i + 1);
			arr.pop_back();
			visited[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (1) {
		v.clear();
		arr.clear();
		cin >> N;
		if (!N) {
			return 0;
		}

		v.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}
		memset(visited, 0, sizeof(visited));
		backtrack(0);
		cout << '\n';
	}
	return 0;
}