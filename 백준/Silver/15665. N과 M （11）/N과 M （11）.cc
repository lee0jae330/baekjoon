#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;

vector<int>v;
vector<int>arr;

void backtrack() {
	if (arr.size() == M) {
		for (int num : arr) {
			cout << num << ' ';
		}
		cout <<'\n';
		return;
	}
	int tmp =-1;
	for (int num : v) {
		if (tmp != num) {
			tmp = num;
			arr.push_back(num);
			backtrack();
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
	backtrack();
	return 0;
}