#include<bits/stdc++.h>

using namespace std;

int N;

int arr[100001];
int visited[100001];
int visited2[100001];



void dfs(int cur, int &cnt) {
	visited[cur] = 1;
	int nxt = arr[cur];
	if (!visited[nxt]) {
		dfs(nxt, cnt);
	}
	else if (!visited2[nxt]) {
		for (int i = nxt; i != cur; i = arr[i]) {
			cnt++;
		}
		cnt++;
	}
	visited2[cur]=1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));
		memset(visited2, 0, sizeof(visited2));
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}

		int cnt =0;
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				dfs(i,cnt);
			}
		}
		cout << N - cnt << '\n';
	}
}