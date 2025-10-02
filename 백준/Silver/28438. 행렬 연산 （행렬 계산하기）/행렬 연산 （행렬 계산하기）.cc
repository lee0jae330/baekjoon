#include<iostream>

using namespace std;

const int SIZE = 5 * 1e5 +1;

int row[SIZE];
int col[SIZE];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, Q;
	cin >> N >> M >> Q;

	while (Q--) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int r, v;
			cin >> r >> v;
			row[r] += v;
		}
		else {
			int c, v;
			cin >> c >> v;
			col[c] += v;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << row[i] + col[j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}