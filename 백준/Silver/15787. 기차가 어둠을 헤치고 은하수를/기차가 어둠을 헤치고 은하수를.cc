#include<iostream>
#include<string>
#include<set>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[100001][21];
set<string>s;

int main(void) {
	fastio();
	int N, M;
	cin >> N >> M;
	while (M--) {
		int num, i;
		cin >> num >>i;
		if (num == 1 || num == 2) {
			int idx;
			cin >> idx;
			if (num == 1) {
				if (!arr[i][idx])
					arr[i][idx] = 1;
			}
			else{
				if (arr[i][idx])
					arr[i][idx] = 0;
			}
		}
		else {
			if (num == 3) {
				for (int x = 19; x > 0; x--) {
					arr[i][x + 1] = arr[i][x];
				}
				arr[i][1] = 0;
			}
			else {
				for (int x = 2; x < 21; x++) {
					arr[i][x - 1] = arr[i][x];
				}
				arr[i][20] = 0;
			}
		}
	}
	int result = 0;
	for (int i = 1; i <= N; i++) {
		string str;
		for (int j = 1; j < 21; j++) {
			if (arr[i][j])
				str += '1';
			else
				str += '0';
		}
		if (s.find(str) == s.end()) {
			result++;
			s.insert(str);
		}
	}
	cout << result << '\n';
}