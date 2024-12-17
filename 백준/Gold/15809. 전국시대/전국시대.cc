#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

const int SIZE = 1e5+1;

int parent[SIZE];
map<int,long long>power;

void init() {
	for (int i = 0; i < SIZE; i++) {
		parent[i] = i;
	}
}

int find(int x) {
	if(x == parent[x] || parent[x] == -1) {
		return parent[x];
	}
	return parent[x] = find(parent[x]);
}

void merge(int x, int y, int flag) {
	x = find(x);
	y = find(y);
	
	long long powerX = power[x];
	long long powerY = power[y];

	if (flag == 1) {
		if (powerX >= powerY) {
			parent[y] = x;
			power[x] += power[y];
		}
		else {
			parent[x] = y;
			power[y] +=power[x];
		}
		
	}
	else {
		if (powerX == powerY) {
			parent[x] = -1;
			parent[y] = -1;
		}
		else if (powerX > powerY) {
			parent[y] = x;
			power[x] -= power[y];
		}
		else {
			parent[x] = y;
			power[y] -=power[x];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	init();

	int N ,M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		long long p;
		cin >> p;
		power[i] = p;
	}

	for (int i = 0; i < M; i++) {
		int O,P,Q;
		cin >> O >> P >> Q;
		merge(P,Q,O);
	}

	set<int>s;
	for (int i = 1; i <= N; i++) {
		if (find(i) != -1) {
			s.insert(find(i));
		}
	}

	vector<long long>v;
	for (auto iter : s) {
		v.push_back(power[iter]);
	}
	sort(v.begin(), v.end());

	cout << v.size() <<'\n';
	for(auto iter : v) {
		cout << iter <<' ';
	}


	return 0;
}