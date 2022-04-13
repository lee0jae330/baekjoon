#include<iostream>
#include<cmath>
#include<map>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

map<long long,int>a, b,l;
map<long long,int>c;
int main(void) {
	fastio();
	long long A,B,L;
	cin >>A>>B>>L;

	if (A == 1 && A == B) {
		cout << L<<'\n';
		return 0;
	}
	while (A>1) {
		int flag=0;
		for (long long i = 2; i <= sqrt(A); i++) {
			if (A % i == 0) {
				a[i]++;
				A/=i;
				flag=1;
				break;
			}
		}
		if (!flag) {
			a[A]++;
			break;
		}
	}
	while (B > 1) {
		int flag = 0;
		for (long long i = 2; i <= sqrt(B); i++) {
			if (B % i == 0) {
				b[i]++;
				B /= i;
				flag = 1;
				break;
			}
		}
		if (!flag) {
			b[B]++;
			break;
		}
	}
	while (L > 1) {
		int flag = 0;
		for (long long i = 2; i <= sqrt(L); i++) {
			if (L % i == 0) {
				l[i]++;
				L /= i;
				flag = 1;
				break;
			}
		}
		if (!flag) {
			l[L]++;
			break;
		}
	}
	int isAone =0,isBone=0;
	if(!a.size())
		isAone=1;
	if(!b.size())
		isBone=1;
	auto iter= l.begin();
	unsigned long long result=1;
	int aa=0,bb=0;
	if (!isAone && !isBone) {
		while (iter != l.end()) {
			long long num=iter->first;
			if (a.find(num) != a.end() && b.find(num) != b.end()) {
				int e=max(a[num], b[num]);
				if (l[num] < e) {
					cout << -1<<'\n';
					return 0;
				}
				else if(l[num]>e)
					result*=pow(num, l[num]);
				
				aa++, bb++;
			}
			else if (a.find(num) != a.end()) {
				if (l[num] < a[num]) {
					cout << -1 << '\n';
					return 0;
				}
				else if(l[num]> a[num])
					result*=pow(num,l[num]);
				aa++;
			}
			else if(b.find(num)!=b.end()){
				if (l[num] < b[num]) {
					cout << -1 << '\n';
					return 0;
				}
				else if(l[num]>b[num])
					result*=pow(num,l[num]);
				bb++;
			}
			else {
				result*=pow(num,l[num]);
			}
			iter++;
		}
		if(aa==a.size()&&bb==b.size())
			cout << result <<'\n';
		else
			cout<<-1<<'\n';
	}
	else if (!isAone) {
		while (iter != l.end()) {
			long long num = iter->first;
			if (a.find(num) != a.end()) {
				if (l[num] < a[num]) {
					cout << -1 << '\n';
					return 0;
				}
				else if(l[num]>a[num])
					result *= pow(num, l[num]);
				aa++;
			}
			else {
				result *= pow(num, l[num]);
			}
			iter++;
		}
		if(aa==a.size())
			cout << result <<'\n';
		else
		{
			cout<<-1<<'\n';
		}
	}
	else if (!isBone) {
		while (iter != l.end()) {
			long long num = iter->first;
			if (b.find(num) != b.end()) {
				if (l[num] < b[num]) {
					cout << -1 << '\n';
					return 0;
				}
				else if(l[num]>b[num])
					result *= pow(num, l[num]);
				bb++;
			}
			else {
				result *= pow(num, l[num]);
			}
			iter++;
		}
		if(bb==b.size())
			cout << result <<'\n';
		else
		{
			cout <<-1<<'\n';
		}
	}
	
	return 0;
}