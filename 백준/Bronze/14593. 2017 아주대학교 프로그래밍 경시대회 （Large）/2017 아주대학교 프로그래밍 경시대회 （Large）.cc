#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector < pair<pair<int, pair<int, int>>, int>>v;

bool comp(pair<pair<int, pair<int, int>>, int>p1, pair<pair<int, pair<int, int>>, int>p2) {
	if (p1.first.first == p2.first.first) {
		if (p1.first.second.first == p2.first.second.first)
			return p1.first.second.second < p2.first.second.second;
		return p1.first.second.first < p2.first.second.first;
	}
	return p1.first.first > p2.first.first;
}


int main(void) {
	fastio();
	int N;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first.first >> v[i].first.second.first >> v[i].first.second.second;
		v[i].second = i + 1;
	}
	sort(v.begin(), v.end(),comp);
	cout << v[0].second;
	return 0;
}