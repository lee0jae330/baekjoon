#include<iostream>
#include<set>;
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

const int SIZE = 1e6+1;

set<pair<int,int>>input;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		input.insert({x,y});
	}

	if (input.size() == 0) {
		cout << N <<'\n';
		return 0;
	}
	
	int mn = input.begin()->first;
	int mx = input.begin()->second;

	int sol = N;

	for (auto iter = next(input.begin()); iter != input.end(); iter++) {
		if (mx >= iter->first && mx <= iter->second) {
			mx = iter->second;
		}
		else if (mx < iter->first) {
			sol -= (mx - mn);
			mn = iter->first;
			mx = iter->second;
		}
	}

	sol -= (mx - mn );

	cout << sol <<'\n';
	
	return 0;
}