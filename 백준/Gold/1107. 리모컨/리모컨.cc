#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stdlib.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[10];
vector<int > v;

int main(void) {
	fastio();
	string N;
	cin >> N;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		arr[num] = 1;
	}
	for (int i = 0; i <= 9; i++) {
		if (!arr[i]) {
			v.push_back(i);
		}
	}
	int tmp = stoi(N);
	int result = abs(tmp - 100);
	string str;
	if (v.size() > 0) {
		for (int i = 0; i < v.size(); i++) {
			int num = v[i];
			num = abs(tmp - num);
			num++;
			result = min(result, num);
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v.size(); j++) {
				int num = v[i] * 10 + v[j];
				num = abs(tmp - num);
				num += 2;
				result = min(result, num);
			}
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v.size(); j++) {
				for (int k = 0; k < v.size(); k++) {
					int num = v[i] * 100 + v[j] * 10 + v[k];
					num = abs(tmp - num);
					num += 3;
					result = min(result, num);
				}
			}
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v.size(); j++) {
				for (int k = 0; k < v.size(); k++) {
					for (int l = 0; l < v.size(); l++) {
						int num = v[i] * 1000 + v[j] * 100 + v[k] * 10 + v[l];
						num = abs(tmp - num);
						num += 4;
						result = min(result, num);
					}
				}
			}
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v.size(); j++) {
				for (int k = 0; k < v.size(); k++) {
					for (int l = 0; l < v.size(); l++) {
						for (int n = 0; n < v.size(); n++) {
							int num = v[i] * 10000 + v[j] * 1000 + v[k] * 100 + v[l] * 10 + v[n];
							num = abs(tmp - num);
							num += 5;
							result = min(result, num);
						}
					}
				}
			}
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v.size(); j++) {
				for (int k = 0; k < v.size(); k++) {
					for (int l = 0; l < v.size(); l++) {
						for (int n = 0; n < v.size(); n++) {
							for (int m = 0; m < v.size(); m++) {
								int num = v[i] * 100000 + v[j] * 10000 + v[k] * 1000 + v[l] * 100 + v[n] * 10 + v[m];
								num = abs(tmp - num);
								num += 6;
								result = min(result, num);
							}
						}
					}
				}
			}
		}
		
	}
	cout << result << '\n';
	return 0;
}