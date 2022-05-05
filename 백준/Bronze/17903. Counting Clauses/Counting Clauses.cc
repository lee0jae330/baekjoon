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
	int N, M,tmp;
	cin >> N >> M;
	if (N >= 8)
		cout << "satisfactory" << '\n';
	else
		cout << "unsatisfactory";
	return 0;
}