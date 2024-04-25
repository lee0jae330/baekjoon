#include<bits/stdc++.h>

using namespace std;

int V,E, S;
vector<pair<int,int>>v[20001];
int dist[20001];
const int INF = 1e9;

void dijkstra(int start) {
	priority_queue<pair<int,int>>pq;
	pq.push({0,start});
	dist[start] = 0;
    
    
	while (!pq.empty()) {
		int d = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
        
        if(dist[cur]<d){
            continue;
        }
        
		for (auto adj : v[cur]) {
			int nxt = adj.first;
			int cost = d + adj.second;

			if (dist[nxt] > cost) {
				dist[nxt] = cost;
				pq.push({-cost, nxt});
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> V >> E;
	cin >> S;

	for (int i = 0; i <= V; i++) {
		dist[i] = INF;
	}

	for (int i = 0; i < E; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({b,cost});
	}
	dijkstra(S);
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF" << '\n';
		}
		else
			cout << dist[i] <<'\n';
	}
	return 0;
}