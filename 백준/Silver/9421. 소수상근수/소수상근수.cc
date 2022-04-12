#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

#define MAX 1000001

vector<int> prime;

int arr[MAX];
set<int> s;

int main(void) {

	fastio();
	arr[1]=1;
	for (long long i = 2; i < 1000001; i++) {
		if(arr[i])
			continue;
		prime.push_back(i);
		for(long long j=i*i;j< 1000001;j+=i)
			arr[j]=1;
	}
	int N;
	cin >>N;
	for (int i = 0; i < prime.size(); i++) {
		s.clear();
		int flag=0;
		if(prime[i]>N)
			break;
		int num=prime[i];
		while (1) {
			int tmp=num;
			int sum=0;
			while (num != 0) {
				int a = num%10;
				sum+=a*a;
				num/=10;
			}
			if (sum == 1) {
				cout << prime[i]<<'\n';
				break;
			}
			else {
				if (s.find(sum) != s.end()) {
					flag=1;
					break;
				}
				else{
					s.insert(sum);
					num=sum;
				}
			}
		}
	}
	return 0;
}