#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string>v;
vector<char>arr[21];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int cnt = 1;
	while (1) {
		v.clear();
		for (int i = 0; i < 21; i++) {
			arr[i].clear();
		}
		int N;
		cin >> N;
		if (!N) {
			return 0;
		}

		for (int i = 0; i < N; i++) {
			string name;
			cin >> name;
			v.push_back(name);
			for (int j = 0; j < N - 1; j++) {
				char c;
				cin >> c;
				arr[i].push_back(c);
			}
		}
		int flag = 0;
		cout << "Group " << cnt++ <<'\n';
		for (int i = 0; i < N; i++) {
			int idx = i - 1;
			for (int j = 0; j < arr[i].size(); j++) {
				if (idx < 0) {
					idx = N - 1;
				}
				if (arr[i][j] == 'N') {
					cout << v[idx] << " was nasty about " << v[i] << '\n';
					flag = 1;
				}
				idx--;
			}
		}
		if (!flag) {
			cout << "Nobody was nasty" << '\n';
		}
		cout <<'\n';
	}
	return 0;
}