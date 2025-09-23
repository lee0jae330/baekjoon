#include<iostream>
#include<deque>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, L;
	cin >> N >> L;

	vector<int>v(N + 1);
	vector<int>sol(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}

	deque<pair<int, int>>dq;

	for (int i = 1; i <= N; i++) {
		if (!dq.empty() && dq.front().second < i - L + 1) {
			dq.pop_front();
		}

		while (!dq.empty() && dq.back().first >= v[i]) {
			dq.pop_back();
		}

		dq.emplace_back(v[i], i);
		sol[i] = dq.front().first;
	}

	for (int i = 1; i <= N; i++) {
		cout << sol[i] << ' ';
	}
	return 0;
}