#include<iostream>
#include<algorithm>
#include<numeric>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int T;
	cin >>T;
	while (T-- > 0) {
		int M,N,x,y;
		cin >>M>>N>>x>>y;

		if (x == y) {
			cout << x <<'\n';
		}
		else {
			
			int num = gcd(M,N);
			num = num * M/num * N/num;
			int flag=0;
			for (int i = x; i <= num; i += M) {
				if (i % N == y % N) {
					cout << i <<"\n";
					flag=1;
					break;
				}
			}
			if(!flag)
				cout << -1<<'\n';
			
		}
	}
	return 0;
}