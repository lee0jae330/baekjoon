#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#include<list>

using namespace std;

const int SIZE = (int)5 * 1e5 + 2;

int pre[SIZE];
int nxt[SIZE];
int N, M;

int parent[SIZE];
vector<int>idx;

void cmd(char c, int x, int y) {
	int preX = pre[x];
	int nextX = nxt[x];

	int preY = pre[y];
	int nextY = nxt[y];
	if (c == 'A') {
		// x를 y 앞으로
		if (nxt[x] == y) {
			return;
		}
		pre[x] = preY;
		nxt[x] = y;
		pre[y] = x;
		if (preX != -1) {
			nxt[preX] = nextX;
		}
		if (nextX != -1) {
			pre[nextX] = preX;
		}
		if (preY != -1) {
			nxt[preY] = x;
		}
	}
	else {
		//x를 y의 뒤로 이동
		if(pre[x] == y)
			return;
		pre[x] = y;
		nxt[x] = nextY;
		nxt[y] = x;

		if (nextX != -1) {
			pre[nextX] = preX;
		}
		if (preX != -1) {
			nxt[preX] = nextX;
		}
		if (nextY != -1) {
			pre[nextY] = x;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	fill(parent, parent + SIZE, -1);

	cin >> N >> M;

	pre[1] = -1;
	nxt[N] = -1;
	for (int i = 2; i <= N; i++) {
		pre[i] = i - 1;
	}

	for (int i = 1; i <= N - 1; i++) {
		nxt[i] = i + 1;
	}

	while (M--) {
		char c;
		int x, y;
		cin >> c >> x >> y;
		cmd(c, x, y);
	}
	int tmp;
	for (int i = 1; i <= N; i++) {
		if (pre[i] == -1) {
			tmp = i;
			break;
		}
	}

	vector<int>lis;
	int index = 0;
	while (tmp != -1) {
		auto iter = lower_bound(lis.begin(), lis.end(), tmp);
		if (iter == lis.end()) {
			if (!lis.empty()) {
				parent[tmp] = idx[idx.size() - 1];
			}
			lis.push_back(tmp);
			idx.push_back(tmp);
		}
		else {
			if (iter != lis.begin()) {
				parent[tmp] = idx[iter - lis.begin() - 1];
			}
			*iter = tmp;
			idx[iter - lis.begin()] = tmp;
		}
		index++;
		tmp = nxt[tmp];
	}
	cout << N - lis.size() << '\n';

	tmp = idx[idx.size() - 1];

	set<int>s;

	while (tmp != -1) {
		pre[tmp] = -2;
		s.insert(tmp);
		tmp = parent[tmp];
	}

	/*
	for (int num : s) {
		cout << num <<' ';
	}
	cout <<'\n';
	*/


	for (int i = 1; i <= N; i++) {
		if (pre[i] == -2)
			continue;
		auto iter = s.lower_bound(i);

		if (iter == s.end()) {
			cout << 'B' << ' ' << i << ' ' << *prev(s.end()) << '\n';
		}
		else {
			cout << 'A' << ' ' << i << ' ' << *iter << '\n';
		}
		s.insert(i);
	}
	return 0;
}