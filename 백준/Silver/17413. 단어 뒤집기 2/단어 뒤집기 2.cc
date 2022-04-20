#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<string>v;

int main(void) {
	fastio();
	string str;
	getline(cin, str);
	int idx = 0, len = str.length();
	int flag = 0;
	if (str[0] == '<')
		flag = 1;
	for (int i = 0; i < len; i++) {
		string tmp;
		if (idx == 0) {
			if (flag) {
				if (str[i] == '>') {
					tmp = str.substr(idx, i - idx+1);
					idx = i + 1;
					if(str[idx]!='<')
						flag = 0;
					v.push_back(tmp);
				}
			}
			else {
				if (str[i] == '<') {
					tmp = str.substr(idx, i - idx);
					idx = i;
					flag = 1;
					reverse(tmp.begin(), tmp.end());
					v.push_back(tmp);
				}
				else if (str[i] == ' ') {
					tmp = str.substr(idx, i - idx);
					idx = i + 1;
					flag = 0;
					reverse(tmp.begin(), tmp.end());
					v.push_back(tmp);
				}
				else if (i == len - 1) {
					tmp = str.substr(idx, i - idx + 1);
					idx = i + 1;
					flag = 0;
					reverse(tmp.begin(), tmp.end());
					v.push_back(tmp);
				}
			}
			
		}
		else {
			if (!flag) { //단어
				if (str[i] == '<') {
					tmp = str.substr(idx, i - idx);
					idx = i;
					flag = 1;
					reverse(tmp.begin(), tmp.end());
					v.push_back(tmp);
				}
				else if (str[i] == ' ') {
					tmp = str.substr(idx, i - idx);
					idx = i + 1;
					flag = 0;
					reverse(tmp.begin(), tmp.end());
					v.push_back(tmp);
				}
				else if (i == len - 1) {
					tmp = str.substr(idx, i - idx+1);
					idx = i + 1;
					flag = 0;
					reverse(tmp.begin(), tmp.end());
					v.push_back(tmp);
				}
				
			}
			else { //태그
				if (str[i] == '>') {
					tmp = str.substr(idx, i - idx+1);
					idx = i + 1;
					if (str[idx] != '<')
						flag = 0;
					v.push_back(tmp);
				}
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i<v.size()-1&&v[i][0] != '<'&&v[i+1][0] != '<')
			cout << ' ';
	}
	cout << '\n';
}