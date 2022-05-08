#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<pair<int, int>>v;

int main(void) {
	fastio();
	int T;
	cin >> T;
	
	while (T--) {
		v.clear();
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			if (i < N - i) {
				v.push_back({ i,N - i });
			}
			else
				break;
		}
		cout << "Pairs for " << N << ": ";
		for (int i = 0; i < v.size(); i++) {
			cout << v[i].first << ' ' << v[i].second;
			if (i != v.size() - 1) {
				cout << ", ";
			}
		}
		cout << '\n';
	}
	return 0;
}