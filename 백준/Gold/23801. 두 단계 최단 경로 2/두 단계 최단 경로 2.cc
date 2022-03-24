#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
#define INF 1e11+1
vector<pair<int, int>>v[100001];
long long int distX[100001];
long long int distZ[100001];

void dijk(int s, long long int* arr) {
	priority_queue<pair<long long int , int >>pq;
	pq.push({ 0,s });
	arr[s] = 0;
	while (!pq.empty()) {
		long long int d = -pq.top().first;
		s = pq.top().second;
		pq.pop();
		if (arr[s] < d)
			continue;
		for (int i = 0; i < v[s].size(); i++) {
			int next = v[s][i].first;	
			long long int cost = v[s][i].second + d;
			if (cost < arr[next]) {
				arr[next] = cost;
				pq.push({ -cost,next });
			}
		}
	}
}

int main(void) {
	fastio();
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	int x, z;
	cin >> x >> z;
	fill(distX, distX + 100001, INF);
	fill(distZ, distZ + 100001, INF);

	dijk(x, distX);
	dijk(z, distZ);

	int P;
	cin >> P;
	long long int result = -1;
	for (int i = 0; i < P; i++) {
		int num;
		cin >> num;
		if (distX[num] != INF && distZ[num] != INF) {
			if (result == -1) {
				result = distX[num] + distZ[num];
			}
			else
				result = min(distX[num] + distZ[num], result);
		}
	}

	cout << result << '\n';
	return 0;
}