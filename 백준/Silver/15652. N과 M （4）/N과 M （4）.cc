#include<iostream>
#include<vector>

using namespace std;

int N,M;

vector<int>v;

void backtrack(int x, int depth) {
	if (depth == M) {
		for (int num : v) {
			cout << num <<' ';
		}
		cout <<'\n';
		return;
	}

	for (int i = x; i <= N; i++) {
		v.push_back(i);
		backtrack(i, depth+1);
		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	backtrack(1, 0);
	return 0;
}