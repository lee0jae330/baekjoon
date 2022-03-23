#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<memory.h>

using namespace std;

#define INF 123456789

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<pair<int, int>>v[200001];
int distS[200001];
int distE[200001];
int visited[200001];


void dijk(int start, int* arr) {
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,start });
	arr[start] = 0;
	while (!pq.empty()) {
		int d = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (arr[cur] < d)
			continue;
		for (int i = 0; i < v[cur].size(); i++) {
			if (visited[v[cur][i].first])
				continue;
			int cost = d + v[cur][i].second;
			if (cost < arr[v[cur][i].first]) {
				arr[v[cur][i].first] = cost;
				pq.push({ -cost, v[cur][i].first });
			}
		}
	}
}

void findShortest(int s, int e) {
	int pre = s;

	while (s != e) {
		int MIN = INF;

		for (int i = 0; i < v[s].size(); i++) {
			int next = v[s][i].first;
			int d = v[s][i].second;
			if (next == pre)
				continue;
			if (distS[s] +d + distE[next] == distS[e]) {
				MIN = next;
			}
			if (MIN == next)
				break;
		}
		if (s != e)
			visited[MIN] = 1;
		pre = s;
		s = MIN;
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
	int s, e;
	cin >> s >> e;
	memset(distS, INF, sizeof(distS));
	memset(distE, INF, sizeof(distE));
	dijk(s, distS);
	dijk(e, distE);
	int result = distS[e];
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}
	findShortest(s, e);
	memset(distE, INF, sizeof(distE));
	dijk(e, distE);

	result += distE[s];
	cout << result << '\n';
	return 0;
}