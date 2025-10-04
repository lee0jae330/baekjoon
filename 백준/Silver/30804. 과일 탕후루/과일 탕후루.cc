#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<int>v;

int arr[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	v.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	int left = 0;
	int right = 0;
	int sol = 1;

	arr[v[left]] = 1;
	arr[v[right]] = 1;

	while (left < N && right <N) {
		int cnt =0;

		for (int i = 0 ;i<10;i++) {
			if (arr[i]) {
				cnt++;
			}
		}

		if (cnt > 2) {
			arr[v[left]]--;
			left++;
		}
		else {
			sol = max(sol, right-left+1);
			right++;
			if (right < N) {
				arr[v[right]]++;
			}
		}
	}
	cout << sol << '\n';
	return 0;
}