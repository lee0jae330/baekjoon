#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<algorithm>

using namespace std;

#define INF 123456789

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<pair<int, int>>v[10001];
int dist[10001];

void dijk(int s) {
	priority_queue<pair<int, int >>pq;
	pq.push({ 0,s });
	dist[s] = 0;
	while (!pq.empty()) {
		int d = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < d)
			continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int cost = d + v[cur][i].second;	
			if (cost < dist[next]) {
				dist[next] = cost; 
				pq.push({ -cost,next });
			}
		}
	}
}


int main(void) {
	fastio();
	int T;
	cin >> T;
	while (T > 0) {
		T--;
		int n, d, c;
		cin >> n >> d >> c;
		for (int i = 1; i <= n; i++)
			v[i].clear();
		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			v[b].push_back({ a,s });
		}
		fill(dist, dist + 10001, INF);
		dijk(c);
		int cnt = 0, mx = -1;
		for (int i = 1; i <= n; i++) {
			if (dist[i] != INF) {
				cnt++;
				mx = max(mx, dist[i]);
			}
		}
		cout << cnt << ' ' << mx << '\n';
	}
	return 0;
}