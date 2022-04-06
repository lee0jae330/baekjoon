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
			num=num - (M-x);
			
			while (num > 0) {
				if (num % N == y % N) {
					cout << num <<'\n';
					break;
				}
				num-=M;
			}
			if(num <=0)
				cout << -1<<'\n';
		}
	}
	return 0;
}