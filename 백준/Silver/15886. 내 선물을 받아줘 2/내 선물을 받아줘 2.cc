#include<iostream>
#include<queue>
#include<set>
#include<vector>
#include<memory.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

char arr[1001];
int visited[1001];
bool isOverlap;
set<int> s;
vector<int> v;
void bfs(int x) {
	queue<int>q;
	visited[x] = 1;
	q.push(x);
	v.push_back(x);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		if (arr[x] == 'E') {
			if (!visited[x + 1]) {
				visited[x + 1] = 1;
				q.push(x + 1);
				v.push_back(x + 1);
			}
		}
		else {
			if (!visited[x - 1]) {
				visited[x - 1] = 1;
				q.push(x - 1);
				v.push_back(x - 1);
			}
		}
	}
}

int main(void) {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		isOverlap = false;
		v.clear();
		memset(visited, 0, sizeof(visited));
		bfs(i);
		int flag = 0;
		for (int i = 0; i < v.size(); i++) {
			if (s.find(v[i]) == s.end()) {
				s.insert(v[i]);
			}
			else {
				flag = 1;
			}
		}

		if (!flag) {
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}