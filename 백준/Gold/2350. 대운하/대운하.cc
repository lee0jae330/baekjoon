#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>

using namespace std;

const int SIZE = 1001;
int parent[SIZE];
int ranking[SIZE];

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
	parent[y] = x;
	return true;
}

priority_queue<tuple<int,int,int>>pq;

int arr[SIZE][SIZE];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		pq.push({cost, x, y});
	}

	init();	

	while (!pq.empty()) {
		auto [cost, x, y] = pq.top();
		pq.pop();
		if (merge(x, y)) {
			for (int i = 1; i <= N; i++) {
				for (int j = i + 1; j <= N; j++) {
					if (!arr[i][j]) {
						if (find(i) == find(j)) {
							arr[i][j] = cost;
						}
					}
				}
			}
		}
	}

	while (K--) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
			swap(a,b);
		}
		cout << arr[a][b] <<'\n';
	}

	return 0;

}
