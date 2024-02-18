//*g5 & #bfs & !@$me & %ko

#include<bits/stdc++.h>

using namespace std;


map<int,vector<int>>m;

set<int>line[11];

set<int>visited;

int N, dest;

void bfs(int x) {
	int cnt =0;
	int cur = 0;
	queue<tuple<int,int,int>>q;
	q.push({x,cur,cnt});
	visited.insert(x);
	while (!q.empty()) {
		tie(x,cur,cnt) = q.front();
		q.pop();
		if (x == dest) {
			cout << cnt <<'\n';
			return;
		}
		vector<int> tmp = m[x];

		for (int l : tmp) { // x가 속한 호선
			for (int tx : line[l]) { // x가 속한 호선에 포함된 역 순환
				if (!x) { //x가 0이면 환승 여부 고려 x
					if (visited.find(tx) == visited.end()) {
						visited.insert(tx);
						q.push({tx,l,cnt});
					}
				}
				else {
					if (visited.find(tx) == visited.end()) {
						int next_cnt = cnt;
						if(cur != l) {
							next_cnt++;
						}
						visited.insert(tx);
						q.push({tx,l,next_cnt});
					}
				}
				
			}
		}
	}
	cout << -1 <<'\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int K;
		cin >> K;
		for (int j = 0; j < K; j++) {
			int num;
			cin >> num;
			line[i].insert(num);
			if (m.find(num) == m.end()) {
				vector<int>tmp;
				tmp.push_back(i);
				m.insert({num,tmp});
			}
			else {
				m[num].push_back(i);
			}
		}
	}
	cin >> dest;
	bfs(0);
	return 0;
}