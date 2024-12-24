#include<iostream>
#include<map>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<cstring>

using namespace std;

int N, M;

const int SIZE = 1e5 + 1;

map<pair<int, int>, int>m;
int visited[SIZE];
vector<int>v[SIZE];

set<int>root;
map<int, vector<int>> edge;
map<int, vector<int>> vertex;

int leaf;

void dfs(int x, int start, int pre, int flag) {
	visited[x] = 1;
	if (vertex.find(start) == vertex.end()) {
		vector<int>tmp;
		tmp.push_back(x);
		vertex[start] = tmp;
	}
	else {
		vertex[start].push_back(x);
	}
	if (x != pre) {
		if (edge.find(start) == edge.end()) {
			vector<int>tmp;
			edge[start] = tmp;
		}
		if (x < pre) {
			edge[start].push_back(m[{x, pre}]);
		}
		else {
			edge[start].push_back(m[{pre, x}]);
		}
	}
	int tmp = 0;
	for (int i = 0; i < v[x].size(); i++) {
		int tx = v[x][i];
		if (visited[tx]) {
			continue;
		}
		tmp = 1;
		dfs(tx, start, x, flag);
	}
	if (!tmp && flag) {
		leaf = x;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
		(x < y) ? m[{x, y}] = i + 1 : m[{y, x}] = i + 1;
	}
	if (N <= 2) {
		cout << -1 << '\n';
		return 0;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(i, i, i, 0);
			root.insert(i);
		}
	}

	int sz = root.size();
	if (sz >= 3) {
		cout << -1 << '\n';
		return 0;
	}
	else if (sz == 2) {
		vector<int>tmp;
		for (auto iter : root) {
			tmp.push_back(iter);
		}

		int x = tmp[0], y = tmp[1];
		int sizeX = vertex[x].size(), sizeY = vertex[y].size();
		if (sizeX == sizeY) {
			// 컴포넌트 2개 & 개수 같으면 안됨
			cout << -1 << '\n';
			return 0;
		}

		cout << sizeX << ' ' << sizeY << '\n';
		for (auto iter : vertex[x]) {
			cout << iter << ' ';
		}
		cout << '\n';

		for (auto iter : edge[x]) {
			cout << iter << ' ';
		}
		cout << '\n';

		for (auto iter : vertex[y]) {
			cout << iter << ' ';
		}
		cout << '\n';

		for (auto iter : edge[y]) {
			cout << iter << ' ';
		}
		cout << '\n';
	}
	else if (sz == 1) {
		memset(visited, 0, sizeof(visited));

		int start = *root.begin();

		dfs(start, start, start, 1);

		memset(visited, 0, sizeof(visited));
		visited[leaf] = 1;
		edge.clear();
		vertex.clear();
		dfs(start, start, start, 0);

		cout << vertex[start].size() << ' ' << 1 << '\n';
		for (auto iter : vertex[start]) {
			cout << iter << ' ';
		}
		cout << '\n';

		for (auto iter : edge[start]) {
			cout << iter << ' ';
		}
		cout << '\n';
		cout << leaf << '\n';

	}
	else {
		cout << -1 << '\n';
		return 0;
	}
}