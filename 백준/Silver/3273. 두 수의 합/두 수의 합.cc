#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N ;
	cin >> N;
	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	int X;
	cin >> X;

	sort(v.begin(), v.end());

	int left = 0, right = N-1;
	int cnt = 0;
	while (left < right) {
		if (v[left] + v[right] >= X) {
			if (v[left] + v[right] == X) {
				cnt++;
			}
			right--;
		}
		else {
			left++;
		}
	}

	cout << cnt <<'\n';
	return 0;
}