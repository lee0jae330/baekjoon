#include<bits/stdc++.h>

using namespace std;


const int INF = 1e9;
int N,M;

int arr[101][101];

void floydWarshall() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			arr[i][j] =INF;
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a>> b >> cost;
		arr[a][b] = min(arr[a][b],cost);
	}

	floydWarshall();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j || arr[i][j] == INF) {
				cout << 0 <<' ';
			}
			else
				cout << arr[i][j]<< ' ';
		}
		cout <<'\n';
	}
	return 0;

}