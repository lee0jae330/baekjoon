#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<map>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<int>crain;
vector<int>box;

bool comp(int a, int b) {
	return a>b;
}

int main(void) {
	fastio();

	int N=1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num=1000000-1;
		cin >> num;
		crain.push_back(num);
	}
	int M=10000;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num=1000000;
		cin >> num;
		box.push_back(num);
	}
	sort(crain.begin(), crain.end(),comp);
	sort(box.begin(), box.end());
	/*for (int i = 0; i < box.size(); i++) {
		cout << box[i]<<' ';
	}
	cout <<'\n';*/
	int time = 0;
	while (box.size() > 0) {
	int flag=0;
		for (int i = 0; i < N; i++) {
			if (box.size() == 0) {
				break;
			}
			auto iter = lower_bound(box.begin(), box.end(), crain[i]);
			if (iter == box.begin()) {
				if (*iter > crain[i])
					continue;
				else {
					flag=1;
					box.erase(iter);
				}
			}
			else if (iter == box.end()) {
				box.erase(iter - 1);
				flag=1;
			}
			else {
				if (*iter > crain[i]) {
					iter--;
				}
				if (iter == box.begin()) {
					if(*iter<=*box.begin())
						box.erase(iter);
					else {
						continue;
					}
				}
				else {
					box.erase(iter);
				}
				flag=1;
			}
		}
		if (!flag) {
			cout <<-1<<'\n';
			return 0;
		}
		/*for (int i = 0; i < box.size(); i++) {
			cout << box[i] << ' ';
		}
		cout << '\n';*/
		time++;
	}
	cout << time << '\n';
	return 0;
}