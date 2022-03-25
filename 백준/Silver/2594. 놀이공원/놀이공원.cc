#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<pair<int, int>>v;

int main(void) {
	fastio();
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		int timeS = start / 100, timeE =end/100;
		int minuteS = start % 100, minuteE = end % 100;
		v.push_back({ 60*timeS+minuteS ,60*timeE+ minuteE});
	}
	sort(v.begin(), v.end());
	int result = 0;
	if (600 < v[0].first - 10)
		result = v[0].first - 10 - 600;
	int end = v[0].second;
	
	for (int i = 1; i < N; i++) {
		int start = v[i].first;
		if (end + 10 < start - 10) {
			int total = start - 10 - (end + 10);
			result = max(result, total);
			end = v[i].second;
		}
		else {
			if (end < v[i].second) {
				end = v[i].second;
			}
		}
	}
	
	if (end + 10 < 22 * 60) {
		result = max(result, 22 * 60 - end - 10);
	}
	cout << result << '\n';
	return 0;
}