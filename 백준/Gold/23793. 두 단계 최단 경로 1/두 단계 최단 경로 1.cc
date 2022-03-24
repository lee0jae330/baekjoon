#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100001
#define LL long long
#define INF 1e9

using namespace std;
int N, M, X, Y, Z;
vector<pair<int, int> > Edge[MAX];
int Cost[3][MAX];

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		Cost[0][i] = INF;
		Cost[1][i] = INF;
		Cost[2][i] = INF;
	}
	for (int i = 0; i < M; i++) {
		int U, V, W;
		cin >> U >> V >> W;
		Edge[U].push_back(make_pair(V, W));
	}
	cin >> X >> Y >> Z;
}

void Dijkstra1(int I, int S, int E) { // 정점 X에서 출발해서 정점 Y를 거치는 경우
	priority_queue<pair<int, int> > PQ;
	Cost[I][S] = 0;
	PQ.push(make_pair(0, S));

	while (!PQ.empty()) {
		int CurCost = -PQ.top().first;
		int CurX = PQ.top().second;
		PQ.pop();

		if (CurX == E) {
			return;
		}

		if (Cost[I][CurX] < CurCost) {
			continue;
		}

		for (int i = 0; i < Edge[CurX].size(); i++) {
			int nextCost = Edge[CurX][i].second;
			int nextX = Edge[CurX][i].first;
			if (Cost[I][nextX] > CurCost + nextCost) {
				Cost[I][nextX] = CurCost + nextCost;
				PQ.push(make_pair(-Cost[I][nextX], nextX));
			}
		}
	};
}

void Dijkstra2() { // 정점 X에서 출발해서 정점 Y를 거치지 않는 경우
	priority_queue<pair<int, int> > PQ;
	Cost[2][X] = 0;
	PQ.push(make_pair(0, X));

	while (!PQ.empty()) {
		int CurCost = -PQ.top().first;
		int CurX = PQ.top().second;
		PQ.pop();

		if (Cost[2][CurX] < CurCost) {
			continue;
		}

		for (int i = 0; i < Edge[CurX].size(); i++) {
			int nextCost = Edge[CurX][i].second;
			int nextX = Edge[CurX][i].first;
			if (nextX == Y) {
				continue;
			}
			if (Cost[2][nextX] > CurCost + nextCost) {
				Cost[2][nextX] = CurCost + nextCost;
				PQ.push(make_pair(-Cost[2][nextX], nextX));
			}
		}
	};
}

void Find_Answer() {
	if ((Cost[0][Y] != INF) && (Cost[1][Z] != INF)) {
		cout << Cost[0][Y] + Cost[1][Z] << " ";
	}
	else {
		cout << -1 << " ";
	}
	if (Cost[2][Z] != INF) {
		cout << Cost[2][Z] << " ";
	}
	else {
		cout << -1 << " ";
	}
	cout << "\n";
}

int main() {
	FASTIO
	Input();
	Dijkstra1(0, X, Y);
	Dijkstra1(1, Y, Z);
	Dijkstra2();
	Find_Answer();

	return 0;
}

