#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<memory.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

map<int, int>m;
set<int>s;

int main(void) {
	fastio();
	while (1) {
		s.clear();
		m.clear();
		int N, M;
		cin >> N >> M;
		if (!N && !M)
			break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int num;
				cin >> num;
				m[num]++;
			}
		}

		for (auto iter = m.begin(); iter != m.end(); iter++)
			s.insert(iter->second);
		auto it = s.end();
		it--;
		it--;
		for (auto iter = m.begin(); iter != m.end(); iter++) {
			if (*it == iter->second) {
				cout << iter->first << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}