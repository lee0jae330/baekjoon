#include<bits/stdc++.h>

using namespace std;

int A, B, C;

set<int>s;

int visited[201][201][201];

void bfs(int a, int b, int c) {
	queue<tuple<int, int, int>>q;
	q.push({ a,b,c });
	visited[a][b][c] = 1;
	while (!q.empty()) {
		tie(a, b, c) = q.front();
		//cout << a << ' '<<b << ' ' <<c <<'\n';
		q.pop();
		if (a == 0) {
			s.insert(c); //중복되는 경우가 있을 수 있으니
		}
		int ta = a;
		int tb = b;
		int tc = c;
		if (a > 0) {
			if (ta + tb > B) {
				int tmp = ta + b - B;
				ta = tmp;
				tb = B;
			}
			else {
				tb += ta;
				ta = 0;
			}
			if (!visited[ta][tb][tc]) {
				visited[ta][tb][tc] = 1;
				q.push({ ta,tb,tc });
			}
			ta = a, tb = b, tc = c;
			if (ta + tc > C) {
				int tmp = ta + tc - C;
				ta = tmp;
				tc = C;
			}
			else {
				tc += ta;
				ta = 0;
			}
			if (!visited[ta][tb][tc]) {
				visited[ta][tb][tc] = 1;
				q.push({ ta,tb,tc });
			}
		}
		ta = a, tb = b, tc = c;
		if (b > 0) {
			if (ta + tb > A) {
				int tmp = ta + tb - A;
				ta = A;
				tb = tmp;
			}
			else {
				ta += tb;
				tb = 0;
			}
			if (!visited[ta][tb][tc]) {
				visited[ta][tb][tc] = 1;
				q.push({ ta,tb,tc });
			}
			ta = a, tb = b, tc = c;
			if (tb + tc > C) {
				int tmp = tb + tc - C;
				tc = C;
				tb = tmp;
			}
			else {
				tc += tb;
				tb = 0;
			}
			if (!visited[ta][tb][tc]) {
				visited[ta][tb][tc] = 1;
				q.push({ ta,tb,tc });
			}
		}
		if (c > 0) {
			ta = a, tb = b, tc = c;
			if (ta + tc > A) {
				int tmp = ta + tc - A;
				ta = A;
				tc = tmp;
			}
			else {
				ta += tc;
				tc = 0;
			}
			if (!visited[ta][tb][tc]) {
				visited[ta][tb][tc] = 1;
				q.push({ ta,tb,tc });
			}
			ta = a, tb = b, tc = c;
			if (tb + tc > B) {
				int tmp = tb + tc - B;
				tb = B;
				tc = tmp;
			}
			else {
				tb += tc;
				tc =0;
			}
			if (!visited[ta][tb][tc]) {
				visited[ta][tb][tc] = 1;
				q.push({ ta,tb,tc });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> A >> B >> C;
	bfs(0,0,C);
	for (auto num : s) {
		cout << num <<' ';
	}
	return 0;
}