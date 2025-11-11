#include<bits/stdc++.h>

using namespace std;

int N;
vector<int>v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (1) {
		cin >> N;
		if (!N) {
			return 0;
		}

		v.clear();
		v.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}

		vector<int>comb(6, 0);
		for (int i = 0; i < N - 6; i++) {
			comb.push_back(1);
		}

		do {
			for (int i = 0; i < N; i++) {
				if (!comb[i]) {
					cout << v[i] << ' ';
				}
			}
			cout << '\n';
		} while (next_permutation(comb.begin(), comb.end()));
		cout << '\n';
	}
	
}