#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<memory.h>

using namespace std;

#define INF 123456789

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<pair<int, int>>v[801];

int distS[801];

void dijk(int s) {

	memset(distS, INF, sizeof(distS));

	priority_queue<pair<int, int>>pq;
	pq.push({ 0,s });
	distS[s] = 0;
	while (!pq.empty()) {
		int d = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (distS[cur] < d)
			continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int cost = d + v[cur][i].second;
			if (cost < distS[next]) {
				distS[next] = cost;
				pq.push({ -cost, next });
			}
		}
	}
}

int main(void) {
	fastio();
	int N, E;
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ b,cost });
		v[b].push_back({ a,cost });
	}
	int x, y;
	cin >> x >> y;
	
	if (!E) {
		cout << -1 << '\n';
		return 0;
	}

	dijk(1);
	bool X=true, Y=true;
	int distX = distS[x], distY=distS[y];
	if (distX == INF)
		X = false;
	if (distY == INF)
		Y = false;
	dijk(x);
	if (X) 
		distX += distS[y];
	if (Y)
		distY += distS[y];

	dijk(y);
	if (X)
		distX += distS[N];
	dijk(x);
	if (Y)
		distY += distS[N];
	if (X && Y) {
		cout << min(distX, distY) << '\n';
	}
	else if (X) {
		cout << distX << '\n';
	}
	else if (Y)
		cout << distY << '\n';
	else
		cout << -1 << '\n';

	return 0;

}