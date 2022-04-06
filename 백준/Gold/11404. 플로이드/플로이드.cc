#include<iostream>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

#define INF 123456789

int dist[101][101];

int main(void) {
	fastio();
	int N,M;
	cin >>N>>M;
	for (int i = 0; i < M; i++) {
		int a, b,c;
		cin >>a>>b>>c;
		if(!dist[a][b])
			dist[a][b]=c;
		else
			dist[a][b]=min(dist[a][b],c);
	}



	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if(!dist[i][j]&&i!=j)
				dist[i][j]=INF;
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if(dist[i][j]==INF||i==j)
				cout << 0 <<' ';
			else
				cout << dist[i][j]<<' ';
		}
		cout <<'\n';
	}
	return 0;
}