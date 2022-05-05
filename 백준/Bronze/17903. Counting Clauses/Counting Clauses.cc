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
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> tmp;
	}
	if (N >= 8)
		cout << "satisfactory" << '\n';
	else
		cout << "unsatisfactory";
	return 0;
}