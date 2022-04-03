#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<memory.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<string> v[27];
vector<string> input[27];
int visited[10001];

int main(void) {
	fastio();
	int N, M;
	cin>>N>>M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >>s;
		v[s[0]-'a'].push_back(s);
	}

	for (int i = 0; i < M; i++) {
		string s;
		cin >>s;
		input[s[0]-'a'].push_back(s);
	}

	for (int i = 0; i < 27; i++) {
		sort(v[i].begin(),v[i].end());
		sort(input[i].begin(), input[i].end());
	}

	int cnt=0;
	for (int i = 0; i < 27; i++) {
		if (v[i].size() > 0 && input[i].size() > 0) {
			memset(visited,0,sizeof(visited));
			int n=v[i].size(), m=input[i].size();
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					if(v[i][j].length()<input[i][k].length())
						break;
					else {
						if(visited[k])
							continue;
						int flag=0, len= input[i][k].length();
						for (int x = 0; x < len; x++) {
							if (v[i][j][x] != input[i][k][x]) {
								flag=1;
								break;
							}
						}
						if (!flag) {
							cnt++;
							visited[k]=1;
						}
					}
				}
			}
		}
	}
	cout << cnt <<'\n';
	return 0;
}