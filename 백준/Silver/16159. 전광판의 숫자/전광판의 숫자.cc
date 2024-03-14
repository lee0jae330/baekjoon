#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<string>v[7];

vector<int> pm;
vector<int>cp;
vector<int>result;

int main(void) {
	fastio();
	for (int i = 0; i < 7; i++) {
		string str;
		getline(cin, str);
		v[i].push_back(str);
	}

	int len = v[0][0].size();
	len /= 6;
	for (int i = 0; i < len; i++) {
		int cnt = 0;
		for (int j = 0; j < 7; j++) {
			for (int k = i * 6; k < i * 6 + 6; k++) {
				if (v[j][0][k] == '1') {
					cnt++;
				}
			}
		}
		switch (cnt) {
		case 6:
			pm.push_back(1);
			break;
		case 8:
			pm.push_back(7);
			break;
		case 9:
			pm.push_back(3);
			break;
		case 10:
			pm.push_back(0);
			break;
		case 11:
			pm.push_back(4);
			break;
		case 12:
			pm.push_back(6);
			break;
		case 13:
			pm.push_back(5);
			break;
		case 14:
			pm.push_back(2);
			break;
		case 15:
			pm.push_back(9);
			break;
		default:
			pm.push_back(8);
		}
	}

	/*cout << '\n';
	for (int i = 0; i < 7; i++) {
		cout << v[i][0] << '\n';
	}*/

	cp = pm;

	if (next_permutation(pm.begin(), pm.end())) {
		for (int i = 0; i < pm.size(); i++) {
			for (int j = 0; j < cp.size(); j++) {
				if (pm[i] == cp[j])
					result.push_back(j);
			}
		}
		for (int i = 0; i < 7; i++) {
			int idx = 0;
			for (int j = 0; j < len; j++) {
				for (int k = 6 * result[idx]; k < 6 * result[idx]+6; k++) {
					cout << v[i][0][k];
				}
				idx++;
			}
			cout << '\n';
		}

	}
	else {
		cout << "The End" << '\n';
	}
	return 0;
}