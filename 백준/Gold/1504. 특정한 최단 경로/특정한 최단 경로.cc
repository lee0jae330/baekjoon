#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

#define INF 123456789

int dist[801];
vector<pair<int, int>>v[801];

void dijk(int x) {
	priority_queue<pair<int, int>>pq;
	dist[x] = 0;
	pq.push({ 0,x });
	while (!pq.empty()) {
		int d = -pq.top().first;
		x = pq.top().second;
		pq.pop();
		if (d > dist[x])
			continue;
		for (int i = 0; i < v[x].size(); i++) {
			int next = v[x][i].first;
			int cost = v[x][i].second + d;
			if (dist[next] > cost) {
				dist[next] = cost;
				pq.push({ -cost, next });
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
		v[b].push_back({ a,cost });
	}
	int v1, v2;
	cin >> v1 >> v2;
	fill(dist, dist + 801, INF);
	dijk(1);
	int x = dist[v1], y = dist[v2];
	bool V1 = true, V2 = true;
	if (x == INF) {
		V1=false;
	}
	if (y == INF) {
		V2=false;
	}
	if (V1&&V2) {
		fill(dist, dist+801,INF);
		dijk(v1);
		x+=dist[v2];
		fill(dist, dist + 801, INF);
		dijk(v2);
		x+=dist[N];

		fill(dist, dist + 801, INF);
		dijk(v2);
		y+=dist[v1];
		fill(dist, dist + 801, INF);
		dijk(v1);
		y+=dist[N];
		if(min(x,y)>=INF)
			cout << -1<<'\n';
		else
			cout << min(x,y)<<'\n';

	}
	else if(V1){
		fill(dist, dist + 801, INF);
		dijk(v1);
		if (dist[v2] == INF) {
			cout << -1<<'\n';
		}
		else {
			x+=dist[v2];
			fill(dist, dist + 801, INF);
			dijk(v2);
			if (dist[N] == INF) {
				cout<<-1<<'\n';
			}
			else{
				x+=dist[N];
				cout << x <<'\n';
			}
		}
	}
	else if(V2){
		fill(dist, dist+801 ,INF);
		dijk(v2);
		if (dist[v1] == INF) {
			cout <<-1<<'\n';
		}
		else {
			y+=dist[v1];
			fill(dist, dist + 801, INF);
			dijk(v1);
			if(dist[N]==INF)
				cout << -1 <<'\n';
			else {
				y+=dist[N];
				cout << y <<'\n';
			}
		}
	}
	else {
		cout << -1<<'\n';
	}
	return 0;
}