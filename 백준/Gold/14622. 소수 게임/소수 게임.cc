#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<cmath>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[5000001];
int visited[5000001];

set<int>s1,s2;

int main(void) {
	fastio();

	arr[1]=1;
	for (int i = 2; i*i < 5000001; i++) {
		if(arr[i])
			continue;
		for(long long j=i*i;j<5000001;j+=i)
			arr[j]=1;
	}


	long long score1=0, score2=0;
	int N;
	cin >>N;
	while (N--) {
		int a,b;
		cin >>a;
		if (arr[a]) {
			if (s2.size() < 3) {
				score2 += 1000;
			}
			else {
				auto iter=s2.end();
				iter--;
				iter--;
				iter--;
				score2+=*iter;
			}
		}
		else {
			if (visited[a]) {
				score1 -= 1000;
			}
			else {
				visited[a]=1;
				s1.insert(a);
			}
		}
		cin >> b;
		if (arr[b]) {
			if (s1.size() < 3) {
				score1 += 1000;
			}
			else {
				auto iter = s1.end();
				iter--;
				iter--;
				iter--;
				score1 += *iter;
			}
		}
		else {
			if (visited[b]) {
				score2 -= 1000;
			}
			else {
				visited[b] = 1;
				s2.insert(b);
			}
		}
	}
	if (score1 > score2) {
		cout << "소수의 신 갓대웅"<<'\n';
	}
	else if (score1 < score2) {
		cout << "소수 마스터 갓규성"<<'\n';
	}
	else
		cout << "우열을 가릴 수 없음"<<'\n';
	return 0;
}