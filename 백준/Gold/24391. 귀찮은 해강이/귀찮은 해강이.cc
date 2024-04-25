#include<bits/stdc++.h>

using namespace std;

int N,M;

int parent[100001];
int ranking[100001];

int find(int x) {
	if (parent[x] != x) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

void merge(int x, int y) {
	int rootX = find(x);
	int rootY = find(y);

	if (rootX != rootY) {
		if (ranking[rootX] < ranking[rootY]) {
			parent[rootX] = rootY;
		}
		else if (ranking[rootX] > ranking[rootY]) {
			parent[rootY] = rootX;
		}
		else {
			parent[rootX] = rootY;
			ranking[rootY++];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	for(int i=1;i<=N;i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >>x >>y ;
		merge(x,y);
	}
	vector<int>course;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		course.push_back(num);
	}
	int cnt = 0;
	int cur = find(course[0]);
	for (int i = 1; i < N; i++) {
		int tmp = find(course[i]);
		if (tmp != cur) {
			cnt ++;
			cur = tmp;
		}
	}
	cout << cnt <<'\n';
	return 0;
}