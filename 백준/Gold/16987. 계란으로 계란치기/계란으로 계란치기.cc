#include<bits/stdc++.h>

using namespace std;

int N;
vector<pair<int,int>>v;

int sol = 0;

void backtrack(int idx, int cnt) {
	if (idx == N) {
		sol = max(sol, cnt);
		return;
	}

	if (v[idx].first <= 0) {
		backtrack(idx+1, cnt);
		return;
	}

	int flag =0;
	for (int i = 0; i < N; i++) {

		if (i == idx) {
			continue;
		}

		if (v[i].first > 0) {
			flag =1;
			int tmp = cnt;
			v[i].first -= v[idx].second;
			v[idx].first -= v[i].second;
			if (v[i].first <= 0) {
				tmp++;
			}
			if (v[idx].first <= 0) {
				tmp++;
			}

			backtrack(idx+1, tmp);
		
			v[i].first += v[idx].second;
			v[idx].first += v[i].second;
		}
	}
	if (!flag) {
		backtrack(idx+1, cnt);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	v.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}

	backtrack(0,0);

	cout << sol <<'\n';
	return 0;
}