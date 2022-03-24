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

#define INF 1000000000

vector<pair<int, int>>v[100001];


int dist1[100001];

int x, y, z,check;

void dijk(int s) {
	priority_queue<pair<long long int, int>>pq;
	pq.push({ 0,s });
	dist1[s] = 0;
	while (!pq.empty()) {
		long long int d = -pq.top().first;
		s = pq.top().second;
		pq.pop();
		if (dist1[s] < d)
			continue;
		for (int i = 0; i < v[s].size(); i++) {
			int next = v[s][i].first;
			long long int cost = d + v[s][i].second;
			if (check == next)
				continue;
			if (cost <dist1[next]) {
				dist1[next] = cost;
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
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ b,cost });
	}

	cin >> x >> y >> z;
	
	fill(dist1, dist1 + sizeof(dist1) / sizeof(int), INF);

	dijk(x);
	long long int xy = dist1[y];

	fill(dist1, dist1 + sizeof(dist1) / sizeof(int), INF);

	dijk(y);
	long long int yz = dist1[z];

	if (xy!=INF&&yz!=INF)
		cout << xy+yz<< ' ';
	else
		cout << -1 << ' ';
	
	check = y;
	fill(dist1, dist1 + sizeof(dist1) / sizeof(int), INF);

	dijk(x);

	if (dist1[z] != INF)
		cout << dist1[z] << ' '<<'\n';
	else
		cout << -1 << ' '<<'\n';
	return 0;
}