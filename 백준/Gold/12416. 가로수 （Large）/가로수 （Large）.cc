#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<string.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<pair<int, int>>v;
vector<pair<int, int>>v1;
vector < pair<int, pair<int, int>>>sol;

bool comp(pair<int, int>p1, pair<int, int>p2) {
	return p1.first < p2.first;
}

int visited[1001][1001];

int main(void) {
	fastio();
	int T, idx = 1;
	cin >> T;
	while (T > 0) {
		int flag = 0;
		T--;
		int N, M, B;
		cin >> N >> M >> B;
		for (int i = 0; i < M; i++) {
			int p, q;
			cin >> p >> q;
			v.push_back({ p,q });
		}
		sort(v.begin(), v.end());
		v1 = v;
		int cnt = 0;
		int result = 0;
		auto it = lower_bound(v.begin(), v.end(), make_pair(B,0),comp);
	
		if (it!=v.end()&&it->first == B) {
			while (it->second > 0) {
				cnt++;
				result += it->first;
				if (cnt == N)
					break;
				it->second--;
			}
		}
		if (cnt >= N) {
			cout << "Case #" << idx << ": " << result << '\n';
		}
		else {
			for (int i = 0; i < v.size(); i++) {
				int n1 = -1, n2;
				int tmp;
				if (v[i].second > 0) {
					n1 = v[i].first;
				}

				if (n1 == -1)
					continue;
				if (n1 >= B) {
					tmp = n1;
					sol.push_back({tmp,{i,-1}});
				}
				else {

					n2 = B - n1;
					auto iter = lower_bound(v.begin(), v.end(), make_pair(n2, 0), comp);
					if (iter == v.end()) {
						continue;
					}

						while (1) {
							if (iter->second == 0 || iter->first + n1 < B || (n1 == iter->first && iter->second == 1)) {
								int tmptmp = iter->first;
								iter = upper_bound(v.begin(), v.end(), make_pair(tmptmp, 0), comp);
							}
							else {
								tmp = n1 + iter->first;
								sol.push_back({ tmp,{i,iter - v.begin()} });
								int tmptmp = iter->first;
								iter = upper_bound(v.begin(), v.end(), make_pair(tmptmp, 0), comp);

							}
							if (iter == v.end())
								break;
						}
					if (iter == v.end() || iter->first > B) {
						flag = -1;
						continue;
					}

				}
			}
			if (sol.size() > 0) {
				sort(sol.begin(), sol.end());
				for (int i = 0; i < sol.size(); i++) {
					if (sol[i].second.second == -1) {
						int id = sol[i].second.first;
						while (1) {
							if (v1[id].second > 0) {
								result += sol[i].first;
								v1[id].second--;
								cnt++;
							}
							else
								break;
							if (cnt == N)
								goto aaa;
						}
					}
					else {
						int id1 = sol[i].second.first, id2 = sol[i].second.second;
						if (id1 == id2) {
							while (1) {
								if (v1[id1].second >= 2) {
									v1[id1].second -= 2;
									result += sol[i].first;
									cnt++;

								}
								else
									break;
								if (cnt == N)
									goto aaa;
							}
						}
						else {
							while (1) {
								if (v1[id1].second > 0 && v1[id2].second > 0) {
									v1[id1].second--; v1[id2].second--;
									result += sol[i].first;
									cnt++;

								}
								else
									break;
								if (cnt == N)
									goto aaa;
							}
						}
						if (cnt == N)
							break;

					}
				}
			}
			aaa:
			if(cnt>=N)
				cout << "Case #" << idx << ": " << result << '\n';
			else
				cout << "Case #" << idx << ": " <<-1 << '\n';

		}
		idx++;
		v.clear(); sol.clear(); v1.clear();
	}
	return 0;
}