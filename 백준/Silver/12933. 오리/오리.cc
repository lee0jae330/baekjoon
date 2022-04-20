#include<iostream>
#include<string>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int visited[2501];
vector<int>v;

int main(void) {
	string str;
	cin >> str;
	int result = 0;
	int len = str.length();
	int num = 1;
	while (1) {
		int flag = 0;
		int tmp = 0;
		for (int i = 0; i < len; i++) {
			if (visited[i])
				continue;

			if (tmp==0 && str[i] == 'q') {
				tmp = 1;
				v.push_back(i);
			}
			else if (tmp == 1 && str[i] == 'u') {
				tmp = 2;
				v.push_back(i);

			}
			else if (tmp == 2 && str[i] == 'a') {
				visited[i] = 1;
				tmp = 3;
			}
			else if (tmp == 3 && str[i] == 'c') {
				v.push_back(i);
				tmp = 4;
			}
			else if (tmp == 4 && str[i] == 'k') {
				v.push_back(i);
				tmp = 0;
				flag = 1;
				for (int i = 0; i < v.size(); i++) {
					visited[v[i]] = 1;
				}
				v.clear();
			}
		}
		if (!flag)
			break;
		else {
			result++;
		}
		v.clear();
	}
	int f = 0;
	for (int i = 0; i < len; i++) {
		if (!visited[i]) {
			f = 1;
		}
	}
	if (!result||f)
		cout << -1 << '\n';
	else
		cout << result << '\n';
	return 0;
}