#include<bits/stdc++.h>

using namespace std;

int N, K;

set<string>visited;
string str[1001];
map<string, int>m;
int path[1001];
int flag = 0;

void bfs(string start, string dest, int A) {
	visited.insert(start);
	queue<pair<string, int>>q;
	q.push({ start , A});
	path[A] = 1234;
	while (!q.empty()) {
		auto [x, pre] = q.front();
		q.pop();
		if (x == dest) {
			return;
		}
		for (int i = 0; i < x.length(); i++) {
			string tmp = x;
			if (tmp[i] == '0') {
				tmp[i] = '1';
			}
			else {
				tmp[i] = '0';
			}
			
			if (visited.find(tmp) == visited.end() && m.find(tmp) != m.end()) {
				//방문x 이고 존재하는 코드일때
				
				path[m[tmp]] = pre;
				q.push({ tmp, m[tmp]});
				visited.insert(tmp);
			}
		}
	}
	flag = 1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		string tmp;
		cin >> tmp;
		str[i] = tmp;
		
		m.insert({ tmp,i });
	}
	int A, B;
	cin >> A >> B;

	string start = str[A];
	string dest = str[B];

	bfs(start, dest, A);
	if (flag) {
		cout << -1 << '\n';
	}
	else {
		stack<int>st;
		st.push(B);
		int tmp = path[B];
		while (1) {
			if (tmp == 1234)
				break;
			st.push(tmp);
			tmp = path[tmp];
		}

		while (!st.empty()) {
			cout << st.top() << ' ';
			st.pop();
		}
	}
	return 0;
	
}