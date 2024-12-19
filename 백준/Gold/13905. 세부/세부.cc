#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<utility>
#include<tuple>

using namespace std;

const int SIZE = 1e5 + 1;

int parent[SIZE];
int ranking[SIZE];
vector<pair<int,int>>v[SIZE];
int visited[SIZE];


struct compare {
	bool operator()(const pair<pair<int,int>,int>&a, const pair<pair<int,int>,int>&b) {
		if (a.second == b.second) {
			if (a.first.first == b.first.first) {
				return a.first.second > b.first.second;
			}
			return a.first.first > b.first.first;
		}
		return a.second > b.second;
	}
};

void init() {
	for (int i = 0; i < SIZE; i++) {
		parent[i]= i;
		ranking[i] =0;
	}
}

int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return false;
	}
	if (ranking[x] < ranking[y]) {
		swap(x,y);
	} else if (ranking[x] == ranking[y]) {
		ranking[x]++;
	}
	
	parent[y] = x;
	return true;
}

void bfs(int x) {
	queue<int>q;
	q.push(x);
	visited[x] = 1e6;
	while (!q.empty()) {
		x = q.front();
		q.pop();
	
		for (int i = 0; i < v[x].size(); i++) {
			int tx =v[x][i].first;
			int value = v[x][i].second;
			if (visited[tx]) {
				continue;
			}
			visited[tx] = min(visited[x], value);
			q.push(tx);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	init();

	int N , M;
	cin >> N >> M;
	int s, e;
	cin >> s >> e; 
	
	priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, compare>pq;

	for (int i = 0; i < M; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		pq.push({{x,y}, -cost});
	}
	
	while (!pq.empty()) {
		auto [x,y] = pq.top().first;
		int cost = pq.top().second;
		bool result = merge(x, y);
		if (result) {
			v[x].push_back({y,-cost});
			v[y].push_back({x,-cost});
		}
		pq.pop();
	}
	
	
	bfs(s);
	cout << visited[e] <<'\n';

	return 0;
}