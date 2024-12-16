#include<iostream>
#include<set>;
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

const int SIZE = 1e6+1;

int parent[SIZE];
int ranking[SIZE];
set<pair<int,int>>input;
set<int>s;
int arr[SIZE];

void init() {
	for (int i = 0; i < SIZE; i++) {
		parent[i] = i;
		ranking[i] = 0;
	}
}

int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	for (int i = x + 1; i <= y; i++) {
		int rootY = find(i);
		if (x == rootY) {
			return;
		}
		if (ranking[x] > ranking[y]) {
			parent[rootY] = x;
		}
		else if (ranking[x] < ranking[y]) {
			parent[x] = rootY;
		}
		else {
			ranking[x]++;
			parent[rootY] = x;
		}
		find(i);
	}

	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	init();
	
	for (int i = 0; i < SIZE; i++) {
		arr[i] = i;
	}
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