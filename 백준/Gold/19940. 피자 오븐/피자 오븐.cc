//*g5 & #bfs & !@$me & %ko

#include<bits/stdc++.h>

using namespace std;

int N;

int visited[62];

void bfs(int x, int num, int h) {
	int addh = 0, addt = 0, mint = 0, addo = 0, mino = 0;
	queue<tuple<int, int, int, int, int, int>>q;
	q.push({ x,addh, addt,mint,addo,mino });
	visited[x] = 1;
	if (x == num) {
		cout << addh + h << ' ' << addt << ' ' << mint << ' ' << addo << ' ' << mino << '\n';
		return;
	}
	while (!q.empty()) {
		tie(x, addh, addt, mint, addo, mino) = q.front();
		q.pop();
		int tx = x - 1;
		if (tx >= 0) {
			if (tx == num) {
				cout << addh + h << ' ' << addt << ' ' << mint << ' ' << addo << ' ' << mino + 1 << '\n';
				return;
			}
			if (!visited[tx]) {
				visited[tx] = 1;
				q.push({ tx,addh,addt,mint, addo, mino + 1 });
			}
		}
		tx = x + 1;
		if (tx <= 60) {
			if (tx == num) {
				cout << addh + h << ' ' << addt << ' ' << mint << ' ' << addo + 1 << ' ' << mino << '\n';
				return;
			}
			if (!visited[tx]) {
				visited[tx] = 1;
				q.push({ tx,addh,addt,mint, addo + 1, mino });
			}
		}
		tx = x - 10;
		if (tx >= 0) {
			if (tx == num) {
				cout << addh + h << ' ' << addt << ' ' << mint + 1 << ' ' << addo << ' ' << mino << '\n';
				return;
			}
			if (!visited[tx]) {
				visited[tx] = 1;
				q.push({ tx,addh,addt,mint + 1, addo, mino });
			}
		}
		tx = x + 10;
		if (tx < 60) {
			if (tx == num) {
				cout << addh + h << ' ' << addt + 1 << ' ' << mint << ' ' << addo << ' ' << mino << '\n';
				return;
			}
			if (!visited[tx]) {
				visited[tx] = 1;
				q.push({ tx,addh,addt + 1,mint, addo, mino });
			}
		}
		tx = x + 60;
		if (tx <= 60) {
			if (tx == num) {
				cout << addh + h + 1 << ' ' << addt + 1 << ' ' << mint << ' ' << addo << ' ' << mino << '\n';
				return;
			}
			if (!visited[tx]) {
				visited[tx] = 1;
				q.push({ tx,addh + 1,addt,mint, addo, mino });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		memset(visited, 0, sizeof(visited));
		cin >> N;
		int addh = N / 60;
		int minute = N % 60;
		bfs(0, minute, addh);
	}
	return 0;
}
