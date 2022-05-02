#include<iostream>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	int flag = 0;
	if (N % A)
		flag = 1;
	int num = N / A + flag;
	int a = B * num;
	flag = 0;
	if (N % C)
		flag = 1;
	num = N / C + flag;
	int b = D * num;
	cout << min(a, b) << '\n';
	return 0;
}