#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

#define INF 1e9+1

int A, B, C;

vector<pair<int, int>>v[100001];

int dist1[100001];
int dist2[100001];
int dist3[100001];

void dijk(int s, int *arr) {
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,s });
	arr[s] = 0;
	while (!pq.empty()) {
		int d = -pq.top().first;
		s = pq.top().second;
		pq.pop();
		if (arr[s] < d)
			continue;
		for (int i = 0; i < v[s].size(); i++) {
			int next = v[s][i].first;
			int cost = d + v[s][i].second;
			if (cost < arr[next]) {
				arr[next] = cost;
				pq.push({ -cost, next });
			}
		}
	}
}

int main(void) {
	fastio();
	int N;
	cin >> N;
	cin >> A >> B >> C;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ b,cost });
		v[b].push_back({ a,cost });
	}

	fill(dist1, dist1 + 100001, INF);
	fill(dist2, dist2 + 100001, INF);
	fill(dist3, dist3 + 100001, INF);

	dijk(A, dist1);
	dijk(B,dist2);
	dijk(C, dist3);
	
	int result = -1, idx;
	for (int i = 1; i <= N; i++) {
		if (i == A || i == B || i == C)
			continue;
		int tmp = min(dist1[i], min(dist2[i], dist3[i]));
		if (result < tmp) {
			result = tmp;
			idx = i;
		}
	}
	
	cout << idx << '\n';
	return 0;
}