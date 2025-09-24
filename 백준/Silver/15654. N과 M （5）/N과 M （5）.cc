#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N,M;

vector<int>v;
vector<int>arr;

int visited[9];

void backtrack(int depth) {
	if (depth == M) {
		for (int num : v) {
			cout << num <<' ';
		}
		cout <<'\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] =1;
			v.push_back(arr[i]);
			backtrack(depth+1);
			visited[i]=0;
			v.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	arr.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	
	backtrack(0);
	return 0;
}