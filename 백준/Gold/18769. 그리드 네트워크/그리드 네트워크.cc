#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

const int SIZE = 25 * 1e4 + 1;
int arr[SIZE];
vector<pair<int, int>>v[SIZE];

int mst(int x) {
	int total =0;
	arr[x] = 1;
	priority_queue<pair<int,int>>pq;
	for (int i = 0; i < v[x].size(); i++) {
		pq.push({-v[x][i].second, v[x][i].first});
	}
	
	while (!pq.empty()) {
		auto [cost, cur] = pq.top();
		pq.pop();

		if(arr[cur]) {
			continue;
		}

		arr[cur] = 1;
		total += -cost;
		
		for (int i = 0; i < v[cur].size(); i++) {
			auto [next, c] = v[cur][i];
			if(arr[next]) {
				continue;
			}
			pq.push({-c, next});
		}
	}
	return total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < SIZE; i++) {
			v[i].clear();
		}
		int R, C;
		cin >> R >> C;
		for (int i = 0; i < R; i++) {
			for (int j = 1; j <= C - 1; j++) {
				int index = C * i + j;
				int cost;
				cin >> cost;
				v[index].push_back({ index + 1, cost });
				v[index + 1].push_back({ index, cost });
			}
		}

		for (int i = 0; i < R - 1; i++) {
			for (int j = 1; j <= C; j++) {
				int index = C*i + j;
				int cost;
				cin >> cost;
				v[index].push_back({index+ C, cost});
				v[index+C].push_back({index, cost});
			}
		}
		cout << mst(1) <<'\n';
	}
	return 0;
}