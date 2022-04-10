#include<iostream>
#include<algorithm>
#include<cstdlib>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int arr[16];
int cnt=0;
int N;

void dfs(int x) {
	if (x == N) {
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++) {
		arr[x]=i;
		int flag=0;
		for (int j = 0; j < x; j++) {
			if (arr[x] == arr[j] || (x - j) == abs(arr[x] - arr[j])) {
				flag=1;
				break;
			}
		}
		if(!flag)
			dfs(x+1);
	}
	
}

int main(void) {
	fastio();
	cin >>N;
	dfs(0);
	cout << cnt <<'\n';
	return 0;
}