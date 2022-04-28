#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[1100][366];
vector<pair<int, int>>v;

int main(void) {
	fastio();
	int N;
	cin >> N;
	int MIN = 366, MAX = -1;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		MIN = min(a, MIN);
		MAX = max(b, MAX);
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	int e = -1,s=-1;
	int max_tmp=-1;
	long long result = 0;
	int flag = 0;
	for (int i = 0; i < v.size(); i++) {
		if (i == 0) {
			s = v[i].first, e = v[i].second;
		}
		else {
			if (e >= v[i].first||e+1==v[i].first) {
				e = max(v[i].second, e);
			}
			else {
				result += (e-s+1) * max_tmp;
				s = v[i].first, e = v[i].second;
				max_tmp = -1;
			}
		}
		int tmp = 0;

		while (1) {
			if (arr[tmp][v[i].first])
				tmp++;
			else
				break;
		}
		max_tmp = max(tmp+1, max_tmp);
		for (int j = v[i].first; j <= v[i].second; j++) {
			arr[tmp][j] = 1;
		}
	}
	result += max_tmp * (e - s + 1);
	cout << result <<'\n';

	return 0;
}
