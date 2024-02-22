#include<bits/stdc++.h>

using namespace std;

map<string, string>m;
set<string>visited;

string y, e;

void bfs(string str) {
	int cnt = 0;
	queue<pair<string, int>>q;
	q.push({ str,cnt });
	visited.insert(str);
	while (!q.empty()) {
		tie(str, cnt) = q.front();
		q.pop();

		if (str==e) {
			cout << cnt << '\n';
			return;
		}

		int sz = str.size();

		for (auto iter = m.begin(); iter != m.end(); iter++) {
			string s = iter->first;

			string tmp;
			for (int i = 0; i < sz; i++) {
				if (i + s.size() <= sz) {
					if (str.substr(i, s.size()) == s) {
						tmp += m[s];
						i = i + s.size() - 1;
					}
					else {
						tmp += str[i];
					}
				}
				else {
					tmp+=str[i];
				}
			}
			if (tmp.size() <= 10 && visited.find(tmp) == visited.end()) {
				q.push({tmp,cnt+1});
				visited.insert(tmp);
			}
		}
	}
	cout << -1<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (1) {
		m.clear();
		visited.clear();
		int N;
		cin >> N;
		if (!N) {
			return 0;
		}

		while (N--) {
			string a, b;
			cin >> a >> b;
			m.insert({ a,b });
		}

		cin >> y >> e;

		bfs(y);
	}
}