#include<iostream>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<int>dist;
vector<int> weight;

int main(void) {
	fastio();
	int T;
	cin >> T;
	while (T--) {
		dist.clear();
		weight.clear();
		int W, N;
		cin >> W >> N;
		dist.resize(N);
		weight.resize(N);
		for (int i = 0; i < N; i++) {
			int d;
			cin >> dist[i] >> weight[i];
		}
		int now = 0, result = 0, flag=0;
		for (int i = 0; i < N; i++) {
			if (now + weight[i] < W) {
				now += weight[i];
			}
			else if (now + weight[i] == W) {
				now = 0;
				result += 2*dist[i];
				if (i == N - 1)
					flag = 1;
			}
			else {
				now = weight[i];
				result += 2*dist[i];
			}
		}
		if(!flag)
			result += 2*dist[N - 1];
		cout << result << '\n';
	}
	return 0;
}