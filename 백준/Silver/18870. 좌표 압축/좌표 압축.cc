#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<int>v;
vector<int>v1;

int main(void) {
	fastio();
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
		v1.push_back(num);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < N; i++) {
		cout << lower_bound(v.begin(), v.end(), v1[i]) - v.begin() << ' ';
	}
	cout << '\n';
	return 0;
}