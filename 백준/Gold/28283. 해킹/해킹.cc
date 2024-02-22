#include<bits/stdc++.h>

using namespace std;

int N,M,X,Y;

vector<int>v[500005];

long long arr[500005];

long long visited[2][500005];

queue<int>q;

bool compare(const long long& a, const long long& b) {
	return a> b;
}

void bfs(int num) {
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int tx = v[x][i];
			if (visited[num][tx] == -1) {
				visited[num][tx] = visited[num][x]+1;
				q.push(tx);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> X >>Y;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	while (M--) {
		int a, b;
		cin >> a>> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	memset(visited,-1,sizeof(visited));

	while (Y--) {
		int num ;
		cin >> num;
		q.push(num);
		visited[0][num] =0;
	}
	bfs(0);

	for (int i = 1; i <= N; i++) {
		if (visited[0][i] == -1 && arr[i]) {
			cout << -1 <<'\n';
			return 0;
		}
	}


	
	vector<long long>tmp;
	
	for (int i = 1; i <= N; i++) {
		if (visited[0][i] != 0) {
			tmp.push_back(visited[0][i]*arr[i]);
		}
	}
	sort(tmp.begin(),tmp.end(),compare);
	
	long long result =0;

	for (int i = 0; i < X; i++) {
		if(i>=tmp.size())
			break;
		result += tmp[i];
	}
	cout << result <<'\n';
	return 0;

}