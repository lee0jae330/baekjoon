#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

map<long long,int > A,B;

int main(void) {
	fastio();
	int N;
	cin >>N;
	for (int i = 0; i < N; i++) {
		int num;
		cin  >>num;
		for (int j = 2; j <= sqrt(num); j++) {
			while (num % j == 0) {
				A[j]++;
				num/=j;
			}
		}
		if(num>1) 
			A[num]++;
	}
	int M;
	cin >>M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		for (int j = 2; j <= sqrt(num); j++) {
			while (num % j == 0) {
				B[j]++;
				num /= j;
			}
		}
		if (num > 1)
			B[num]++;
	}
	/*for(auto iter= A.begin();iter!=A.end();iter++)
		cout << iter->first<<' '<<iter->second<<'\n';
	for (auto iter = B.begin(); iter != B.end(); iter++)
		cout << iter->first << ' ' << iter->second << '\n';*/
	auto a= A.begin(), b= B.begin();
	long long tmp=1;
	int f=0;
	while (a != A.end() && b != B.end()) {
		if(a->first > b -> first)
			b++;
		else if(a->first<b->first) {
			a++;
		}
		else {
			int cnt = min(a->second, b->second);
			while (cnt--) {
				tmp *= a->first;
				if (tmp >= 1000000000) {
					f=1;
					tmp%=1000000000;
				}
			}
			a++;
			b++;
		}
	}
	if (f) {
		string s= to_string(tmp);
		for(int i=0;i<9-s.length();i++)
			cout <<0;
	}
	cout << tmp << '\n';
	return 0;
}
