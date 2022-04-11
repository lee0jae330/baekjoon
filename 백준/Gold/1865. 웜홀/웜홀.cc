#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

#define INF 1e9+1
long long dist[501];
vector<pair<pair<int,int>,int>>v;
bool isCycle;
int visited[501];
void bellman(int N, int x) {
	fill(dist, dist + 501, INF);

	dist[x]=0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < v.size(); j++) {
			int from = v[j].first.first;
			int to = v[j].first.second;
			int cost = v[j].second;

			//if(dist[from]==INF)
			//	continue;
			if (dist[to] > dist[from] + cost) {
				dist[to]=dist[from]+cost;
			}
		}
	}
	
	for (int i = 0; i < v.size(); i++) {
		int from = v[i].first.first;
		int to = v[i].first.second;
		int cost = v[i].second;

		//if (dist[from] == INF)
		//	continue;
		if (dist[to] > dist[from] + cost) {
			isCycle= true;
			return;
		}
	}
	isCycle= false;
}

int main(void) {
	fastio();
	int T;
	cin >>T;
	while (T--) {
		v.clear();
		int N ,M ,W;
		cin >> N>>M>>W;
		for (int i = 0; i < M; i++) {
			int a,b, c;
			cin >>a>>b>>c;
			v.push_back({{a,b},c});
			v.push_back({{b,a},c});
			visited[a]=1;
		}
		for (int i = 0; i < W; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			v.push_back({ {a,b},-c });

			visited[a]=1;
		}
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				v.push_back({{i,1},0});
				v.push_back({{1,i},0});
			}
		}
		int flag=0;

		bellman(N, 1);


		if (isCycle) {
			cout << "YES"<<'\n';
		}
		else {
			cout << "NO"<<'\n';
		}
	}
	return 0;
}