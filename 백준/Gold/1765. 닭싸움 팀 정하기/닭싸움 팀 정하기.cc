#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

const int SIZE = 1e3 + 1;
int parent[SIZE];
int ranking[SIZE];
int enemy[SIZE];

void init() {
	for (int i = 0; i < SIZE; i++) {
		parent[i] = i;
		ranking[i] = 0;
	}
}

int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x= find(x);
	y = find(y);
	if (x == y) {
		return;
	}

	if (ranking[x] < ranking[y]) {
		swap(x,y);
	}
	else if (ranking[x] == ranking[y]) {
		ranking[x]++;
	}
	parent[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	int N;
	cin >> N;
	int M;
	cin >> M;
	while (M--) {
		char c;
		int x,y;
		cin >> c >> x >> y;
		if (c == 'E') {
			if (!enemy[x] && !enemy[y]) {
				enemy[x] = y;
				enemy[y] = x;
			}
			else if (enemy[x] && enemy[y]) {
				merge(enemy[x],y);
				merge(x,enemy[y]);
			}
			else if (enemy[x]) {
				merge(y,enemy[x]);
			}
			else {
				merge(x, enemy[y]);
			}
			
		}
		else {
			merge(x,y);
		}
	}

	set<int>s;
	for (int i = 1; i <= N; i++) {
		s.insert(find(i));
	}
	cout << s.size() <<'\n';
	return 0;
}