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

#define INF 10001

int dist[101];
int arr[101];
vector<pair<int,int>>v[101];

void dijk(int x) {
	priority_queue<pair<int,int>>pq;
	pq.push({0,x});
	dist[x]=0;
	while (!pq.empty()) {
		int cost =-pq.top().first;
		x= pq.top().second;
		pq.pop();
		if(dist[x]<cost)
			continue;
		for (int i = 0; i < v[x].size(); i++) {
			int next =v[x][i].first;
			int c = v[x][i].second+cost;
			if (c < dist[next]) {
				dist[next]=c;
				pq.push({-c, next});
			}
		}
	}
}

int main(void) {
	fastio();
	int N,M,R;
	cin >>N>>M>>R;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < R; i++) {
		int a, b,cost;
		cin >>a>>b>>cost;
		v[a].push_back({b,cost});
		v[b].push_back({a,cost});
	}
	int result =-1;
	for (int i = 1; i <= N; i++) {
		fill(dist,dist+101,INF);
		dijk(i);
		int tmp=0;
		for (int j = 1; j <= N; j++) {
			if (dist[j] <= M) {
				tmp+=arr[j];
			}
		}
		result= max(result, tmp);
	}
	cout <<result <<'\n';
	return 0;
}