#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>

using namespace std;

vector<tuple<int,int,int>>v;

int N,M,K;

const int SIZE = 1e3 + 1;
int parent[SIZE];
int ranking[SIZE];

struct compare {
	bool operator()(const tuple<int,int,int>&a, const tuple<int,int,int>&b) {
		auto &[a1,a2,a3] = a;
		auto &[b1,b2,b3] = b;

		if (a3 == b3) {
			if (a1 == b1) {
				return a2 > b2;
			}
			return a1 > b1;
		}
		

		return a3 > b3;
	}
};

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

bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return false;
	}

	if (ranking[x] < ranking[y]) {
		swap(x,y);
	}
	else if (ranking[x] == ranking[y]) {
		ranking[x]++;
	}
	parent[y]= x;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> K;
	for (int i = 1; i <= M; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({x,y,i});
	}

	int flag= 0;
	for (int i = 0; i < K; i++) {
		priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,compare>pq;
		init();
		for (int j = i; j < M; j++) {
			pq.push(v[j]);
		}
		
		int score = 0;
		while (!pq.empty()) {
			auto [x,y,cost]  = pq.top();
			pq.pop();
			if (merge(x, y)) {
				score += cost;
			}
		}

		int root = find(1);
		for (int j = 2; j <= N; j++) {
			if (root != find(j)) {
				flag=1;
				break;
			}
		}
		if (flag) {
			cout <<  0 <<' ';
			continue;
		}
		cout << score <<' ';
	}
	return 0;
}