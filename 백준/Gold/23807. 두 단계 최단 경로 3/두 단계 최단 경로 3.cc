#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

using namespace std;

#define INF 1e11+1

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<pair<int, int>>v[100001];
long long distX[100001];
vector<int> vertex;

long long dist[101][100001];

void dijk(int s,long long *arr) {
	priority_queue<pair<long long, int >>pq;
	pq.push({ 0,s });
	arr[s] = 0;
	while (!pq.empty()) {
		long long d = -pq.top().first;
		s = pq.top().second;
		pq.pop();
		if (arr[s] < d)
			continue;
		for (int i = 0; i < v[s].size(); i++) {
			int next = v[s][i].first;
			long long cost = d + v[s][i].second;
			if (cost < arr[next]) {
				arr[next] = cost;
				pq.push({ -cost ,next });
			}
		}
	}
}


int  main(void) {
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
	int  num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int n;
		cin >> n;
		vertex.push_back(n);
	}
	vector<int> comb(3, 1);
	for (int i = 0; i < num - 3; i++)
		comb.push_back(0);
	fill(distX, distX + 100001, INF);
	dijk(x, distX);
	
	sort(vertex.begin(), vertex.end());
	for (int i = 0; i < 101; i++) {
		fill(dist[i], dist[i] + 100001, INF);
	}

	map<int, int>m;
	for (int i = 0; i < vertex.size(); i++) {
		m.insert({ vertex[i],i });
		dijk(vertex[i], dist[i]);
	}

	sort(comb.begin(), comb.end());
	long long result = -1;
	do {
		vector<int>sol;
		for (int i = 0; i < comb.size(); i++) {
			if (comb[i]) {
				sol.push_back(vertex[i]);
			}
		}
		sort(sol.begin(), sol.end());
		do {
			long long tmp = -1;
			if (distX[sol[0]] != INF) {
				if (dist[m[sol[0]]][sol[1]] != INF) {
					if (dist[m[sol[1]]][sol[2]] != INF) {
						if (dist[m[sol[2]]][z] != INF) {
							tmp = distX[sol[0]];
							tmp += dist[m[sol[0]]][sol[1]];
							tmp += dist[m[sol[1]]][sol[2]];
							tmp += dist[m[sol[2]]][z];
							if (result == -1)
								result = tmp;
							else
								result = min(tmp, result);
						}
					}
				}
			}

		} while (next_permutation(sol.begin(), sol.end()));
	} while (next_permutation(comb.begin(), comb.end()));
	cout << result << '\n';
	return 0;
}