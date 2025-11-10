#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;

int visited[10];

vector<int>v;
vector<int>arr;

void backtrack(int n) {
	if (arr.size() == M) {
		for (int num : arr) {
			cout << num <<' ';
		}
		cout<< '\n';
		return;
	}

	int tmp = -1; 
	for (int i = n; i < N; i++) {
		if (!visited[i] && tmp != v[i]) {
			visited[i] =1;
			tmp = v[i];
			arr.push_back(v[i]);
			backtrack(i+1);
			visited[i] =0;
			arr.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	backtrack(0);
	return 0;
}