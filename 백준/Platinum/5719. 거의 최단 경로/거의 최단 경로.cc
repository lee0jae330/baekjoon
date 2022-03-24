#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>
#include<map>

using namespace std;

#define INF 123456789

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<pair<int, int>>v[501];
vector<pair<int, int>>v1[501];
vector<pair<int, int>>v2[501];

int distS[501];
int distD[501];

void dijk(int s) {
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
				pq.push({ -cost,next });
			}
		}
	}
}


void dijk1(int s) {
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,s });
	distD[s] = 0;
	while (!pq.empty()) {
		int d = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (distD[cur] < d)
			continue;
		for (int i = 0; i < v1[cur].size(); i++) {
			int next = v1[cur][i].first;
			int cost = d + v1[cur][i].second;
			
			if (cost < distD[next]) {
				distD[next] = cost;
				pq.push({ -cost,next });
			}
		}
	}
}

void dijk2(int s) {
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,s });
	distS[s] = 0;
	while (!pq.empty()) {
		int d = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (distS[cur] < d)
			continue;
		for (int i = 0; i < v2[cur].size(); i++) {
			int next = v2[cur][i].first;
			int cost = d + v2[cur][i].second;
			if (cost < distS[next]) {
				distS[next] = cost;
				pq.push({ -cost,next });
			}
		}
	}
}

int visited[501];

void find_short(int s, int e) {
	queue<pair<int,int>>q;
	q.push({ s,s });
	memset(visited, 0, sizeof(visited));
	visited[s] = 1;

	while (!q.empty()) {
		s = q.front().first;
		int pre = q.front().second;
		q.pop();
	
		for (int i = 0; i < v[s].size(); i++) {
			int next = v[s][i].first;
			int cost = v[s][i].second;
			if (distS[s] + cost + distD[next] == distS[e]) {
				continue;
			}
			else {
				v2[s].push_back({ next,cost });
			}
			if(!visited[next])
				q.push({ next, s });
			visited[next] = 1;
		}
	}
}

int main(void) {
	fastio();
	while (1) {
		int N, M;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			v[i].clear(), v1[i].clear(),v2[i].clear();
		}
		if (!N && !M)
			break;
		int s, d;
		cin >> s >> d;
		for (int i = 0; i < M; i++) {
			int a, b, cost;
			cin >> a >> b >> cost;
			v[a].push_back({ b,cost });
			v1[b].push_back({ a,cost });

		}
		memset(distS, INF, sizeof(distS));
		memset(distD, INF, sizeof(distD));
		dijk(s);
		dijk1(d);
		find_short(s, d);
		
		memset(distS, INF, sizeof(distS));
		distS[d] = 100000000;
		dijk2(s);
		int result = distS[d];
		if (result == 100000000)
			cout << -1 << '\n';
		else
			cout << result << '\n';
	}
	return 0;
}