#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<memory.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int visited[10001];

void bfs(int a, int b) {
	visited[a]=1;
	queue<pair<int,string>>q;
	q.push({a,""});
	while (!q.empty()) {
		int x=q.front().first;
		string str=q.front().second;
		q.pop();
		int tmp = 2*x %10000;
		if (!visited[tmp]) {
			if (tmp == b) {
				cout << str+'D' <<'\n';
				return;
			}
			else {
				visited[tmp]=1;
				q.push({tmp, str+'D'});
			}
		}
		tmp=x;
		if (tmp == 0) {
			if (!visited[9999]) {
				tmp=9999;
				if (tmp == b) {
					cout << str+'S'<<'\n';
					return;
				}
				else {
					visited[9999]=1;
					q.push({9999,str+'S'});
				}
			}
		}
		else {
			if (!visited[tmp - 1]) {
				tmp-=1;
				if (tmp == b) {
					cout <<str+'S'<<'\n';
					return;
				}
				else {
					visited[tmp]=1;
					q.push({tmp,str+'S'});
				}
			}
		}
		
		tmp=x;
		if (tmp != 0) {
			if (tmp < 1000) {
				tmp *= 10;
			}
			else {
				int num = tmp / 1000;
				tmp %= 1000;
				tmp *= 10;
				tmp += num;
			}
			if (!visited[tmp]) {
				if (tmp == b) {
					cout << str + 'L' << '\n';
					return;
				}
				else {
					visited[tmp] = 1;
					q.push({ tmp, str + 'L' });
				}
			}
			tmp = x;
			int num = tmp / 10;
			tmp = tmp % 10;
			tmp*=1000;
			tmp+=num;
			if (!visited[tmp]) {
				if (tmp == b) {
					cout << str+'R'<<'\n';
					return;
				}
				else {
					visited[tmp]=1;
					q.push({tmp,str+'R'});
				}
			}
		}
		

	}
}

int main(void) {
	fastio();
	int N;
	cin >>N;
	while (N>0) {
		N--;
		memset(visited, 0, sizeof(visited));
		int a, b;
		cin >>a >>b;
		bfs(a,b);
	}
	return 0;
}