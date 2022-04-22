#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<string>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

string sarr[1002];
int visited[1002];

vector<int>v[1002];

string result;
unsigned long long result1;

void dfs(int x, int y, string s) {
	if(visited[x])
		return;
	if (x == y) {
		//s+=sarr[y];
		unsigned long long tmp = stoull(s);
		tmp%=1000000007;
		result1=tmp;
		return;
	}
	visited[x]=1;
	for (int i = 0; i < v[x].size(); i++) {
		if(visited[v[x][i]])
			continue;
		string tmp1= s+sarr[v[x][i]];
		unsigned long long tmp= stoull(tmp1);
		tmp%=1000000007;
		tmp1=to_string(tmp);
		dfs(v[x][i], y, tmp1);
	}
}


int main(void) {
	fastio();
	int N=4,Q=10;
	cin >>N>>Q;
	for (int i = 1; i <= N; i++) {
		cin >>sarr[i];
	}
	for (int i = 0; i < N - 1; i++) {
		int a=i+1, b=i+2;
		cin >>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < Q; i++) {
		int x=1,y=4;
		cin >>x >>y;
		memset(visited,0,sizeof(visited));
		dfs(x,y,sarr[x]);
		cout << result1<<'\n';
	}
return 0;	
}